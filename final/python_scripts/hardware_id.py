def getserial():
  # Extract serial from cpuinfo file
  cpuserial = "0000000000000000"
  try:
    f = open('/proc/cpuinfo','r')
    for line in f:
      if line[0:6]=='Serial':
        cpuserial = line[10:26]
    f.close()
  except:
    cpuserial = "ERROR000000000"
  return cpuserial


serial = getserial()
serial_short = serial[-5:]

print(serial_short)

f = open('../temp_files/hardware_id.txt', 'w')
f.write(serial_short)