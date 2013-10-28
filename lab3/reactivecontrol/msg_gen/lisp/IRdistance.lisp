; Auto-generated. Do not edit!


(cl:in-package reactivecontrol-msg)


;//! \htmlinclude IRdistance.msg.html

(cl:defclass <IRdistance> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (IR1
    :reader IR1
    :initarg :IR1
    :type cl:float
    :initform 0.0)
   (IR2
    :reader IR2
    :initarg :IR2
    :type cl:float
    :initform 0.0))
)

(cl:defclass IRdistance (<IRdistance>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <IRdistance>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'IRdistance)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name reactivecontrol-msg:<IRdistance> is deprecated: use reactivecontrol-msg:IRdistance instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <IRdistance>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader reactivecontrol-msg:header-val is deprecated.  Use reactivecontrol-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'IR1-val :lambda-list '(m))
(cl:defmethod IR1-val ((m <IRdistance>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader reactivecontrol-msg:IR1-val is deprecated.  Use reactivecontrol-msg:IR1 instead.")
  (IR1 m))

(cl:ensure-generic-function 'IR2-val :lambda-list '(m))
(cl:defmethod IR2-val ((m <IRdistance>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader reactivecontrol-msg:IR2-val is deprecated.  Use reactivecontrol-msg:IR2 instead.")
  (IR2 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <IRdistance>) ostream)
  "Serializes a message object of type '<IRdistance>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'IR1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'IR2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <IRdistance>) istream)
  "Deserializes a message object of type '<IRdistance>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'IR1) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'IR2) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<IRdistance>)))
  "Returns string type for a message object of type '<IRdistance>"
  "reactivecontrol/IRdistance")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'IRdistance)))
  "Returns string type for a message object of type 'IRdistance"
  "reactivecontrol/IRdistance")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<IRdistance>)))
  "Returns md5sum for a message object of type '<IRdistance>"
  "2fb8c917f4e8d8ed20f3f1a673aff4cf")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'IRdistance)))
  "Returns md5sum for a message object of type 'IRdistance"
  "2fb8c917f4e8d8ed20f3f1a673aff4cf")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<IRdistance>)))
  "Returns full string definition for message of type '<IRdistance>"
  (cl:format cl:nil "Header header~%~%#Value in cm of IR~%float64 IR1~%float64 IR2~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'IRdistance)))
  "Returns full string definition for message of type 'IRdistance"
  (cl:format cl:nil "Header header~%~%#Value in cm of IR~%float64 IR1~%float64 IR2~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <IRdistance>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <IRdistance>))
  "Converts a ROS message object to a list"
  (cl:list 'IRdistance
    (cl:cons ':header (header msg))
    (cl:cons ':IR1 (IR1 msg))
    (cl:cons ':IR2 (IR2 msg))
))
