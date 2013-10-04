
(cl:in-package :asdf)

(defsystem "arbitrator-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "ArbAngle" :depends-on ("_package_ArbAngle"))
    (:file "_package_ArbAngle" :depends-on ("_package"))
  ))