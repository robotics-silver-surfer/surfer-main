; Auto-generated. Do not edit!


(cl:in-package Ref-msg)


;//! \htmlinclude BotToRef.msg.html

(cl:defclass <BotToRef> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (botID
    :reader botID
    :initarg :botID
    :type cl:fixnum
    :initform 0))
)

(cl:defclass BotToRef (<BotToRef>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <BotToRef>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'BotToRef)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name Ref-msg:<BotToRef> is deprecated: use Ref-msg:BotToRef instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <BotToRef>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Ref-msg:header-val is deprecated.  Use Ref-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'botID-val :lambda-list '(m))
(cl:defmethod botID-val ((m <BotToRef>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader Ref-msg:botID-val is deprecated.  Use Ref-msg:botID instead.")
  (botID m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <BotToRef>) ostream)
  "Serializes a message object of type '<BotToRef>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'botID)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <BotToRef>) istream)
  "Deserializes a message object of type '<BotToRef>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'botID)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<BotToRef>)))
  "Returns string type for a message object of type '<BotToRef>"
  "Ref/BotToRef")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'BotToRef)))
  "Returns string type for a message object of type 'BotToRef"
  "Ref/BotToRef")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<BotToRef>)))
  "Returns md5sum for a message object of type '<BotToRef>"
  "2d11442c1144e852870ea968f1816b57")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'BotToRef)))
  "Returns md5sum for a message object of type 'BotToRef"
  "2d11442c1144e852870ea968f1816b57")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<BotToRef>)))
  "Returns full string definition for message of type '<BotToRef>"
  (cl:format cl:nil "Header header~%uint8 botID~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'BotToRef)))
  "Returns full string definition for message of type 'BotToRef"
  (cl:format cl:nil "Header header~%uint8 botID~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <BotToRef>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <BotToRef>))
  "Converts a ROS message object to a list"
  (cl:list 'BotToRef
    (cl:cons ':header (header msg))
    (cl:cons ':botID (botID msg))
))
