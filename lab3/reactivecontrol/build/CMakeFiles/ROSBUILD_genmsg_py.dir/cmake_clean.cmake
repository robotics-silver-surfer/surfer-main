FILE(REMOVE_RECURSE
  "../msg_gen"
  "../msg_gen"
  "../src/reactivecontrol/msg"
  "CMakeFiles/ROSBUILD_genmsg_py"
  "../src/reactivecontrol/msg/__init__.py"
  "../src/reactivecontrol/msg/_Control.py"
  "../src/reactivecontrol/msg/_IRdistance.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
