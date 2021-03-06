/*!
* \brief File system related functions.
*        Part of the Common Cross-platform Geographic Library (CCGL)
*
* \author Liangjun Zhu (crazyzlj)
* \version 1.0
* \changelog  2018-05-02 - lj - Make part of CCGL.\n
*/
#ifndef CCGL_UTILS_FILESYSTEM_H
#define CCGL_UTILS_FILESYSTEM_H

#include <vector>
#include <cstring>

#include "basic.h"

using std::vector;

namespace ccgl {
/*!
 * \namespace utils_filesystem
 * \brief File Input and output related functions
 */
namespace utils_filesystem {
#ifndef windows
/*!
 * \brief Copy file in unix-based platform
 * \param[in] srcfile \a char source file path
 * \param[in] dstfile \a char destination file path
 * \TODO Add this functionality on Windows
 */
int copyfile_unix(const char *srcfile, const char *dstfile);

#endif /* windows */

/*!
 * \brief Check the given directory path is exists or not.
 */
bool DirectoryExists(const string& dirpath);

/*!
 * \brief Clean a directory if exists, otherwise create it.
 */
bool CleanDirectory(const string& dirpath);

/*!
 * \brief Delete a directory if exists.
 * \refer Windows: https://stackoverflow.com/questions/734717/how-to-delete-a-folder-in-c
 *        Linux: https://www.linuxquestions.org/questions/programming-9/deleting-a-directory-using-c-in-linux-248696/
 */
bool DeleteDirectory(const string& dirpath, bool del_subdirs = true);

/*!
 * \brief Get the root path of the current executable file
 * \return \a string root path
 */
string GetAppPath();

/*!
 * \brief Return the absolute file path from a given file path
 * \param[in] full_filename
 * \return absolutePath
 * \sa GetPathFromFullName
 */
string GetAbsolutePath(string const& full_filename);

/*!
 * \brief Return the file name from a given file's path
 * \param[in] full_filename
 * \return CoreFileName
 * \sa GetPathFromFullName
 */
string GetCoreFileName(string const& full_filename);

/*!
 * \brief Return the suffix of a given file's path
 * \param[in] full_filename
 * \return Suffix
 * \sa GetPathFromFullName
 */
string GetSuffix(string const& full_filename);

/*!
 * \brief Replace the suffix by a given suffix
 * \param[in] full_filename
 * \param[in] new_suffix
 * \return new full_filename
 */
string ReplaceSuffix(string const& full_filename, string const& new_suffix);

/*!
 * \brief Get Path From full file path string
 * \param[in] full_filename \a string
 * \return filePath string
 * \sa GetCoreFileName
 */
string GetPathFromFullName(string const& full_filename);

/*!
 * \brief Return a flag indicating if the given file exists
 * \param[in] filename String path of file
 * \return True if Exists, and false if not.
 */
bool FileExists(string const& filename);

/*!
 * \brief Return a flag indicating if the given path exists
 * \param[in] path String path
 * \return True if Exists, and false if not.
 */
bool PathExists(string const& path);

/*!
 * \brief Delete the given file if existed.
 * \param[in] filepath \string
 * \return 0 if deleted successful, else return nonzero value, e.g. -1.
 */
int DeleteExistedFile(const string& filepath);

/*!
 * \brief Find files in given paths
 * \param[in] lp_path, expression
 * \param[out] vec_files
 * \return 0 means success
 */
int FindFiles(const char* lp_path, const char* expression, vector<string>& vec_files);

/*!
 * \brief Load short plain text file as string vector, ignore comments begin with '#' and empty lines
 * \param[in] filepath Plain text file path
 * \param[out] content_strs Each line without CRLF or LF stored in vector
 * \return True when read successfully, and false with empty content_strs when failed
 */
bool LoadPlainTextFile(const string& filepath, vector<string>& content_strs);
} /* namespace: utils_filesystem */

} /* namespace: ccgl */

#endif /* CCGL_UTILS_FILESYSTEM_H */
