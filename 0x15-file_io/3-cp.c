#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

/**
 * Copies the contents of the file at the specified path to another file at the
 * specified path.
 *
 * @param fromPath The path of the file to copy from.
 * @param toPath The path of the file to copy to.
 * @return 0 if the operation was successful, or a positive integer representing
 * the error code if an error occurred.
 */
int copyFile(const char *fromPath, const char *toPath) {
    // Open the file to copy from.
    int fromFd = open(fromPath, O_RDONLY);
    if (fromFd < 0) {
        return 1;
    }

    // Open or create the file to copy to.
    int toFd = open(toPath, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (toFd < 0) {
        close(fromFd);
        return 2;
    }

    // Copy the file's contents in chunks of BUFFER_SIZE bytes.
    char *buffer = (char *) malloc(BUFFER_SIZE);
    ssize_t bytesRead, bytesWritten;
    while ((bytesRead = read(fromFd, buffer, BUFFER_SIZE)) > 0) {
        bytesWritten = write(toFd, buffer, bytesRead);
        if (bytesWritten < 0) {
            free(buffer);
            close(fromFd);
            close(toFd);
            return 3;
        }
    }

    // Check for read errors.
    if (bytesRead < 0) {
        free(buffer);
        close(fromFd);
        close(toFd);
        return 4;
    }

    // Clean up and exit successfully.
    free(buffer);
    close(fromFd);
    close(toFd);
    return 0;
}
