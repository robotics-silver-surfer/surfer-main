FILE(REMOVE_RECURSE
  "../msg_gen"
  "../msg_gen"
  "../src/ballDetector/msg"
  "CMakeFiles/ROSBUILD_genmsg_lisp"
  "../msg_gen/lisp/ballLocation.lisp"
  "../msg_gen/lisp/_package.lisp"
  "../msg_gen/lisp/_package_ballLocation.lisp"
  "../msg_gen/lisp/debugTimes.lisp"
  "../msg_gen/lisp/_package.lisp"
  "../msg_gen/lisp/_package_debugTimes.lisp"
  "../msg_gen/lisp/ballDebug.lisp"
  "../msg_gen/lisp/_package.lisp"
  "../msg_gen/lisp/_package_ballDebug.lisp"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_lisp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
