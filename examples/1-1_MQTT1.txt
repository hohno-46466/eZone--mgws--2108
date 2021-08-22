#
# (1-1) Basic messaging over MQTT
#
# Last update: Thu Jul 22 20:59:12 JST 2021 by @hohno_at_kuimc
#
# Public domain
#

# ----------------------------------------------------------

# Description: Publish and subscribe text messages via local MQTT broker

# Requirements: mosquitto, mosquitto_pub, mosquitto_sub on the POSIX environment (such as ubuntu on WSL on Windodws10)

# ----------------------------------------------------------

# (Step1) Start MQTT Broker on your terminal No.1 (T1)

(T1)$ mosquitto

# ----------------------------------------------------------

# (Step2) Subscribe (receive) message from MQTT broker on your terminal No.2 (T2)

(T2)$ mosquitto_sub -t MGWS/Test99

# Note: Type control-C to stop the subscriber (mosquitto_sub) above. 

# ----------------------------------------------------------

# (Step3) Publish (send) a message from your terminal No.2 (T2) to terminal No.3 (T3)

(T3)$ echo "Hello,Halifax!" 

(T3)$ echo "Hello,Halifax!" | mosquitto_pub -l -t MGWS/Test99

(T3)$ mosquitto_pub -l -t MGWS/Test99 # You can type as much as you want until typing Control-D
	Type any messages as you want...
	The quick brown fox jumps over the lazy dog
	1
	2
	3
	Control-D

# ----------------------------------------------------------

