--- base/files/drive_info_posix.cc.orig	2025-03-05 08:14:56 UTC
+++ base/files/drive_info_posix.cc
@@ -24,7 +24,7 @@ namespace base {
 
 std::optional<DriveInfo> GetFileDriveInfo(const FilePath& file_path) {
   DriveInfo drive_info;
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   drive_info.has_seek_penalty = false;
   return drive_info;
 #elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
