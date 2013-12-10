"""autogenerated by genpy from ballDetector/ballDebug.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class ballDebug(genpy.Message):
  _md5sum = "f0dbcd340db400b8721875b15029f990"
  _type = "ballDetector/ballDebug"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """bool sendDebugImages
bool sendDebugTimes 

"""
  __slots__ = ['sendDebugImages','sendDebugTimes']
  _slot_types = ['bool','bool']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       sendDebugImages,sendDebugTimes

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(ballDebug, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.sendDebugImages is None:
        self.sendDebugImages = False
      if self.sendDebugTimes is None:
        self.sendDebugTimes = False
    else:
      self.sendDebugImages = False
      self.sendDebugTimes = False

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_struct_2B.pack(_x.sendDebugImages, _x.sendDebugTimes))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 2
      (_x.sendDebugImages, _x.sendDebugTimes,) = _struct_2B.unpack(str[start:end])
      self.sendDebugImages = bool(self.sendDebugImages)
      self.sendDebugTimes = bool(self.sendDebugTimes)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_struct_2B.pack(_x.sendDebugImages, _x.sendDebugTimes))
    except struct.error as se: self._check_types(se)
    except TypeError as te: self._check_types(te)

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 2
      (_x.sendDebugImages, _x.sendDebugTimes,) = _struct_2B.unpack(str[start:end])
      self.sendDebugImages = bool(self.sendDebugImages)
      self.sendDebugTimes = bool(self.sendDebugTimes)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_2B = struct.Struct("<2B")