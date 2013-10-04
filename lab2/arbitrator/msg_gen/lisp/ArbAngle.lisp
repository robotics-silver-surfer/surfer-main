; Auto-generated. Do not edit!


(cl:in-package arbitrator-msg)


;//! \htmlinclude ArbAngle.msg.html

(cl:defclass <ArbAngle> (roslisp-msg-protocol:ros-message)
  ((angle
    :reader angle
    :initarg :angle
    :type cl:float
    :initform 0.0))
)

(cl:defclass ArbAngle (<ArbAngle>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ArbAngle>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ArbAngle)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name arbitrator-msg:<ArbAngle> is deprecated: use arbitrator-msg:ArbAngle instead.")))

(cl:ensure-generic-function 'angle-val :lambda-list '(m))
(cl:defmethod angle-val ((m <ArbAngle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader arbitrator-msg:angle-val is deprecated.  Use arbitrator-msg:angle instead.")
  (angle m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ArbAngle>) ostream)
  "Serializes a message object of type '<ArbAngle>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'angle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ArbAngle>) istream)
  "Deserializes a message object of type '<ArbAngle>"
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
  "4edb55038e2b888976a0c0c56935341c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ArbAngle)))
  "Returns md5sum for a message object of type 'ArbAngle"
  "4edb55038e2b888976a0c0c56935341c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ArbAngle>)))
  "Returns full string definition for message of type '<ArbAngle>"
  (cl:format cl:nil "# Gyro reported angle in degrees~%float64 angle~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ArbAngle)))
  "Returns full string definition for message of type 'ArbAngle"
  (cl:format cl:nil "# Gyro reported angle in degrees~%float64 angle~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ArbAngle>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ArbAngle>))
  "Converts a ROS message object to a list"
  (cl:list 'ArbAngle
    (cl:cons ':angle (angle msg))
))
