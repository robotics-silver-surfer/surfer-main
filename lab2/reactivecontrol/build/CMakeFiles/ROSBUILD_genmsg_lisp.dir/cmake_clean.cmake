FILE(REMOVE_RECURSE
  "../msg_gen"
  "../msg_gen"
  "../src/reactivecontrol/msg"
  "CMakeFiles/ROSBUILD_genmsg_lisp"
  "../msg_gen/lisp/IRdistance.lisp"
  "../msg_gen/lisp/_package.lisp"
  "../msg_gen/lisp/_package_IRdistance.lisp"
  "../msg_gen/lisp/Control.lisp"
  "../msg_gen/lisp/_package.lisp"
  "../msg_gen/lisp/_package_Control.lisp"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_lisp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
