#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

typedef struct {
    int fd;           // descriptor
    char *buffer;     // pointer
    char *buffer_pos; // position in buffer
    int buffer_size;  // size
    int is_eof;       
    int is_error;    
} File;

int _flushbuf(File *file) {
    if (file == NULL || file->buffer == NULL) return EOF;

    int num_written = write(file->fd, file->buffer, file->buffer_pos - file->buffer);
    if (num_written < 0) {
        file->is_error = 1;
        return EOF;
    }

    file->buffer_pos = file->buffer; 
    return 0;
}

int fflush(File *file) {
    if (file == NULL) return EOF;
    return _flushbuf(file);
}

int fclose(File *file) {
    if (file == NULL) return EOF;

    if (fflush(file) == EOF) {
        free(file->buffer);
        free(file);
        return EOF;
    }

    if (close(file->fd) == -1) {
        file->is_error = 1;
        free(file->buffer);
        free(file);
        return EOF;
    }

    free(file->buffer);
    free(file);
    return 0;
}

File *fopen_custom(const char *filename, const char *mode) {
    int fd;
    if (mode[0] == 'w')
        fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    else if (mode[0] == 'r')
        fd = open(filename, O_RDONLY);
    else
        return NULL;

    if (fd == -1) return NULL;

    File *file = malloc(sizeof(File));
    if (file == NULL) {
        close(fd);
        return NULL;
    }

    file->fd = fd;
    file->buffer = malloc(BUFFER_SIZE);
    if (file->buffer == NULL) {
        close(fd);
        free(file);
        return NULL;
    }

    file->buffer_pos = file->buffer;
    file->buffer_size = BUFFER_SIZE;
    file->is_eof = 0;
    file->is_error = 0;
    return file;
}

int fwrite_custom(const void *ptr, size_t size, size_t nmemb, File *file) {
    if (file == NULL || file->buffer == NULL) return EOF;

    size_t total_bytes = size * nmemb;
    size_t bytes_to_write = total_bytes;

    while (bytes_to_write > 0) {
        size_t space_left = file->buffer + file->buffer_size - file->buffer_pos;

        if (bytes_to_write <= space_left) {
            memcpy(file->buffer_pos, ptr, bytes_to_write);
            file->buffer_pos += bytes_to_write;
            bytes_to_write = 0;
        } else {
            memcpy(file->buffer_pos, ptr, space_left);
            file->buffer_pos += space_left;
            ptr = (char *)ptr + space_left;
            bytes_to_write -= space_left;

            if (_flushbuf(file) == EOF) return EOF;
        }
    }

    return total_bytes / size;
}
