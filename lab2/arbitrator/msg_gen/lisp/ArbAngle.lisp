; Auto-generated. Do not edit!


(cl:in-package arbitrator-msg)


;//! \htmlinclude ArbAngle.msg.html

(cl:defclass <ArbAngle> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (angle
    :reader angle
    :initarg :angle
    :type cl:float
    :initform 0.0)
   (x_axis
    :reader x_axis
    :initarg :x_axis
    :type cl:float
    :initform 0.0)
   (y_axis
    :reader y_axis
    :initarg :y_axis
    :type cl:float
    :initform 0.0))
)

(cl:defclass ArbAngle (<ArbAngle>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ArbAngle>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ArbAngle)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name arbitrator-msg:<ArbAngle> is deprecated: use arbitrator-msg:ArbAngle instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <ArbAngle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader arbitrator-msg:header-val is deprecated.  Use arbitrator-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'angle-val :lambda-list '(m))
(cl:defmethod angle-val ((m <ArbAngle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader arbitrator-msg:angle-val is deprecated.  Use arbitrator-msg:angle instead.")
  (angle m))

(cl:ensure-generic-function 'x_axis-val :lambda-list '(m))
(cl:defmethod x_axis-val ((m <ArbAngle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader arbitrator-msg:x_axis-val is deprecated.  Use arbitrator-msg:x_axis instead.")
  (x_axis m))

(cl:ensure-generic-function 'y_axis-val :lambda-list '(m))
(cl:defmethod y_axis-val ((m <ArbAngle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader arbitrator-msg:y_axis-val is deprecated.  Use arbitrator-msg:y_axis instead.")
  (y_axis m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ArbAngle>) ostream)
  "Serializes a message object of type '<ArbAngle>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'angle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'x_axis))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'y_axis))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ArbAngle>) istream)
  "Deserializes a message object of type '<ArbAngle>"
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
    (cl:setf (cl:slot-value msg 'angle) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x_axis) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y_axis) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ArbAngle>)))
  "Returns string type for a message object of type '<ArbAngle>"
  "arbitrator/ArbAngle")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ArbAngle)))
  "Returns string type for a message object of type 'ArbAngle"
  "arbitrator/ArbAngle")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ArbAngle>)))
  "Returns md5sum for a message object of type '<ArbAngle>"
  "d6d2618c3edfd25dca188f9806ba616a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ArbAngle)))
  "Returns md5sum for a message object of type 'ArbAngle"
  "d6d2618c3edfd25dca188f9806ba616a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ArbAngle>)))
  "Returns full string definition for message of type '<ArbAngle>"
  (cl:format cl:nil "Header header~%~%# Target angle~%float64 angle~%~%# Current axis values~%float32 x_axis~%float32 y_axis~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ArbAngle)))
  "Returns full string definition for message of type 'ArbAngle"
  (cl:format cl:nil "Header header~%~%# Target angle~%float64 angle~%~%# Current axis values~%float32 x_axis~%float32 y_axis~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ArbAngle>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     8
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ArbAngle>))
  "Converts a ROS message object to a list"
  (cl:list 'ArbAngle
    (cl:cons ':header (header msg))
    (cl:cons ':angle (angle msg))
    (cl:cons ':x_axis (x_axis msg))
    (cl:cons ':y_axis (y_axis msg))
))
