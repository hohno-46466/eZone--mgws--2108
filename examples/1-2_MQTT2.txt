#
# (1-2) Basic messaging over the public MQTT (MQTT broker on the internet)
#
# Last update: Thu Jul 22 20:59:12 JST 2021 by @hohno_at_kuimc
#
# Public domain
#

# ----------------------------------------------------------

# Description: Publish and subscribe text messages via public MQTT broker on the croud

# Requirements: mosquitto, mosquitto_pub, mosquitto_sub on the POSIX environment (such as ubuntu on WSL on Windodws10)

# ----------------------------------------------------------

# (Step1) Subscribe messages from the public MQTT broker (on your terminal No.2)

# Note: Replace "XX" in "TestXX" below with your two digit number

(T2)$ mosquitto_sub -t MGWS/TestXX -h broker.hivemq.com -I clientId

# Note: Type control-C to stop the subscriber (mosquitto_sub) above. 

# ----------------------------------------------------------

# (Step2) Publish a message from your terminal No.2 (T2) to terminal No.3 (T3) via public MQTT broker.

# Note: Replace "XX" in "TestXX" below with your two digit number

(T3)$ echo "Hello,Halifax!" 

(T3)$ echo "Hello,Halifax!" | mosquitto_pub -l -t MGWS/TestXX -h broker.hivemq.com -I clientId

(T3)$ mosquitto_pub -l -t MGWS/Test99 -h broker.hivemq.com -l cientId # You can type as much as you want until typing Control-D
	Type any messages as you want...
	The quick brown fox jumps over the lazy dog
	1
	2
	3
	Control-D

# ----------------------------------------------------------

