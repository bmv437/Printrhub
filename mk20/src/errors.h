//
// Created by Phillip Schuster on 27.09.16.
//

#ifndef MK20_ERRORS_H
#define MK20_ERRORS_H

enum class DownloadError {
    UnknownError = 0,
    ConnectionFailed = 1,
    Timeout = 2,
    Forbidden = 3,
    FileNotFound = 4,
    InternalServerError = 5,
    RemoveOldFilesFailed = 6,
    PrepareDownloadedFileFailed = 7,

    MK20UpdateError = 100,

    ESPUpdateNoUpdates = 200,
    ESPUpdateFailed = 201,

    LocalFileNotFound = 300,
    LocalFileOpenForReadFailed = 301,

    TargetFileOpenForWriteFailed = 400
};

enum class FirmwareUpdateError {
    UnknownError = 0,
};


#endif //MK20_ERRORS_H
