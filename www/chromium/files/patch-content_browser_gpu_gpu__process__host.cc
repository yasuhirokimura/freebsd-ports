--- content/browser/gpu/gpu_process_host.cc.orig	2021-05-12 22:05:52 UTC
+++ content/browser/gpu/gpu_process_host.cc
@@ -231,8 +231,8 @@ static const char* const kSwitchNames[] = {
     sandbox::policy::switches::kNoSandbox,
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
-    !BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_BSD) || (defined(OS_LINUX) && !BUILDFLAG(IS_CHROMEOS_ASH) && \
+    !BUILDFLAG(IS_CHROMEOS_LACROS))
     switches::kDisableDevShmUsage,
 #endif
 #if defined(OS_WIN)
@@ -1177,7 +1177,7 @@ bool GpuProcessHost::LaunchGpuProcess() {
   std::unique_ptr<base::CommandLine> cmd_line =
       std::make_unique<base::CommandLine>(base::CommandLine::NO_PROGRAM);
 #else
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   int child_flags = gpu_launcher.empty() ? ChildProcessHost::CHILD_ALLOW_SELF
                                          : ChildProcessHost::CHILD_NORMAL;
 #elif defined(OS_MAC)
