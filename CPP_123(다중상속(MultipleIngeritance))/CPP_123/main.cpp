#include <iostream>

using namespace std;

class USBDevice
{
private:
    long m_id;
    
public:
    USBDevice(long id) : m_id(id) {}
    
    long getID() { return m_id };
    
    void plugAndPlay() {}
};

class NetworkDevice
{
private:
    long m_id;
    
public:
    NetworkDevice(long id) : m_id(id) {}
    
    long getID() { return m_id; }
    
    void networking() {}
};

class USBNetworkDevice : public USBDevice, public NetworkDevice
{
public:
    USBNetworkDevice(long usb_id, long net_id)
    : USBDevice(usb_id), NetworkDevice(net_id)
    {}
    /*
     경우에 따라서 한개를 받을수도 있다
     USBNetworkDevice(long id)
     : USBDevice(id), NetworkDevice(id)
     {}
     */
};


int main()
{
    USBNetworkDevice my_device(3.14, 6.022);
    
    my_device.networking();
    my_device.plugAndPlay();
    
    // 문제는 중복되는 함수에서 생긴다!
//    my_device.getID();  //   ambiguous 문제 발생, 따라서 아래와 같이 사용
    my_device.USBDevice::getID();
    my_device.NetworkDevice::getID();
    
    
    
    return 0;
}
