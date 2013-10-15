
(cl:in-package :asdf)

(defsystem "arbitrator-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "ArbData" :depends-on ("_package_ArbData"))
    (:file "_package_ArbData" :depends-on ("_package"))
  ))