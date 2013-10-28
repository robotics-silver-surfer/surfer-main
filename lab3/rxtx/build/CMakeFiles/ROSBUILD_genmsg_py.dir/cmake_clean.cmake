FILE(REMOVE_RECURSE
  "../msg_gen"
  "../msg_gen"
  "../src/rxtx/msg"
  "CMakeFiles/ROSBUILD_genmsg_py"
  "../src/rxtx/msg/__init__.py"
  "../src/rxtx/msg/_rxtxData.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
