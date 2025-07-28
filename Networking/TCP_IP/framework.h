
/*_______________________________________________________________________
|    TCP/IP Layers                   TCP/IP Protocols                  |
| ____________________ ______________________________________________  |
|| TCP/IP Layer      | |  HTTP  |  FTP  | Telnet |  SMTP  |   DNS    | |
||___________________| |________|_______|________|________|__________| |
|| Transport Layer   | |      TCP           |        UDP             | |
||___________________| |____________________|________________________| |
|| Network Layer     | |   IP    |   ARP    |   ICMP   |   IGMP      | |
||___________________| |_________|__________|__________|_____________| |
|| Network Interface | |              |              |   Other Link  | |
||      Layer        | |   Ethernet   |  Token Ring  |Layer Protocols| |
||___________________| |______________|______________|_______________| |
|______________________________________________________________________|
*/

// Internet Protocol (IP)=> A routable protocol that uses IP addresses to deliver packets to network devices.
//                          IP is an intentionally unrealiable protocol (it doesn't guarantee deliver of its info.)

//32-bit octen binary IP address:

/*________________________________________
|                                       |
|  The network ID   |   The network ID  |
|_______________________________________|
|  11111111.11111111.11111111.11111111  |
|_______________________________________|
*/
