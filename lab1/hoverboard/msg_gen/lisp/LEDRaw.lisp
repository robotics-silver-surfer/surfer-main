; Auto-generated. Do not edit!


(cl:in-package hoverboard-msg)


;//! \htmlinclude LEDRaw.msg.html

(cl:defclass <LEDRaw> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (led33_red
    :reader led33_red
    :initarg :led33_red
    :type cl:fixnum
    :initform 0)
   (led33_green
    :reader led33_green
    :initarg :led33_green
    :type cl:fixnum
    :initform 0))
)

(cl:defclass LEDRaw (<LEDRaw>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <LEDRaw>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'LEDRaw)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name hoverboard-msg:<LEDRaw> is deprecated: use hoverboard-msg:LEDRaw instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <LEDRaw>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader hoverboard-msg:header-val is deprecated.  Use hoverboard-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'led33_red-val :lambda-list '(m))
(cl:defmethod led33_red-val ((m <LEDRaw>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader hoverboard-msg:led33_red-val is deprecated.  Use hoverboard-msg:led33_red instead.")
  (led33_red m))

(cl:ensure-generic-function 'led33_green-val :lambda-list '(m))
(cl:defmethod led33_green-val ((m <LEDRaw>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader hoverboard-msg:led33_green-val is deprecated.  Use hoverboard-msg:led33_green instead.")
  (led33_green m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <LEDRaw>) ostream)
  "Serializes a message object of type '<LEDRaw>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let* ((signed (cl:slot-value msg 'led33_red)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'led33_green)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <LEDRaw>) istream)
  "Deserializes a message object of type '<LEDRaw>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'led33_red) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'led33_green) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<LEDRaw>)))
  "Returns string type for a message object of type '<LEDRaw>"
  "hoverboard/LEDRaw")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'LEDRaw)))
  "Returns string type for a message object of type 'LEDRaw"
  "hoverboard/LEDRaw")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<LEDRaw>)))
  "Returns md5sum for a message object of type '<LEDRaw>"
  "3179455e6b99aaaed74f73183b013321")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'LEDRaw)))
  "Returns md5sum for a message object of type 'LEDRaw"
  "3179455e6b99aaaed74f73183b013321")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<LEDRaw>)))
  "Returns full string definition for message of type '<LEDRaw>"
  (cl:format cl:nil "Header header~%~%# 1 to turn on the specified LED, 0 to turn it off, ~%# 2 to toggle, -1 to keep current value.~%int8 led33_red~%int8 led33_green~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'LEDRaw)))
  "Returns full string definition for message of type 'LEDRaw"
  (cl:format cl:nil "Header header~%~%# 1 to turn on the specified LED, 0 to turn it off, ~%# 2 to toggle, -1 to keep current value.~%int8 led33_red~%int8 led33_green~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <LEDRaw>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <LEDRaw>))
  "Converts a ROS message object to a list"
  (cl:list 'LEDRaw
    (cl:cons ':header (header msg))
    (cl:cons ':led33_red (led33_red msg))
    (cl:cons ':led33_green (led33_green msg))
))
