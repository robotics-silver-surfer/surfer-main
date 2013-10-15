FILE(REMOVE_RECURSE
  "../msg_gen"
  "../msg_gen"
  "../src/arbitrator/msg"
  "CMakeFiles/ROSBUILD_genmsg_lisp"
  "../msg_gen/lisp/ArbData.lisp"
  "../msg_gen/lisp/_package.lisp"
  "../msg_gen/lisp/_package_ArbData.lisp"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_lisp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
