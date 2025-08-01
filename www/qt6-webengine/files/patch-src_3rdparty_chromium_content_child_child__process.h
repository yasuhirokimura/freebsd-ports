--- src/3rdparty/chromium/content/child/child_process.h.orig	2024-07-30 11:12:21 UTC
+++ src/3rdparty/chromium/content/child/child_process.h
@@ -79,7 +79,7 @@ class CONTENT_EXPORT ChildProcess {
     return io_thread_runner_.get();
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Changes the thread type of the child process IO thread.
   void SetIOThreadType(base::ThreadType thread_type);
 #endif
