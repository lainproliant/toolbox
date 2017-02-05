#ifndef __LAIN_FILE_H
#define __LAIN_FILE_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cerrno>
#include "exception.h"

namespace lain {
   using namespace std;

   class FileException : public Exception {
      using Exception::Exception;
   };

   namespace file {
      inline ifstream open_r(const string& filename,
                             ios::openmode mode = ios::in) {
         try {
            ifstream infile;
            infile.exceptions(ios::badbit);
            infile.open(filename, mode);
            return infile;

         } catch (exception& e) {
            throw FileException(
               tfm::format("Cannot open file '%s' for reading: %s",
                  filename, strerror(errno)));
         }
      }

      inline ofstream open_w(const string& filename,
                             ios::openmode = ios::out) {
         try {
            ofstream outfile;
            outfile.exceptions(ios::badbit);
            outfile.open(filename);
            return outfile;

         } catch (exception& e) {
            throw FileException(
               tfm::format("Cannot open file '%s' for writing: %s",
                  filename, strerror(errno)));
         }
      }

      inline fstream open_rw(const string& filename,
                             ios::openmode mode = ios::in | ios::out) {
         try {
            fstream outfile;
            outfile.exceptions(ios::badbit);
            outfile.open(filename, mode);
            return outfile;

         } catch (exception& e) {
            throw FileException(
               tfm::format("Cannot open file '%s' for writing: %s",
                  filename, strerror(errno)));
         }
      }
   }
}

#endif
