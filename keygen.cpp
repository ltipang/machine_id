// keygen.cpp : Defines the entry point for the application.
//

#include "keygen.h"
#include "os/cpu_info.hpp"
#include "os/dmi_info.hpp"
#include "os/os.h"
#include "os/network.hpp"
#include "machineid.h"

using namespace std;

int main()
{
	cout << "Hello CMake." << endl;
	//license::os::CpuInfo cpu;
	//cout << "Cpu Vendor       :" << cpu.vendor() << endl;
	//cout << "Cpu Brand        :" << cpu.brand() << endl;
	//cout << "Cpu hypervisor   :" << cpu.is_hypervisor_set() << endl;
	//cout << "Cpu model        :0x" << std::hex << ((long)cpu.model()) << std::dec << endl;
	license::os::DmiInfo dmi_info;
	cout << "Bios vendor      :" << dmi_info.bios_vendor() << endl;
	cout << "Bios description :" << dmi_info.bios_description() << endl;
	cout << "System vendor    :" << dmi_info.sys_vendor() << endl << endl;
	cout << "==================" << endl;

	DiskInfo diskInfos[10];
	size_t disk_info_size;
	getDiskInfos(diskInfos, &disk_info_size);
	cout << "diskinfo  device  :" << diskInfos[0].device << endl << endl;
	cout << "diskinfo sn   :" << diskInfos[0].disk_sn << endl << endl;
	cout << "diskinfo label   :" << diskInfos[0].label << endl << endl;
	char str[MAX_PATH];
	//getUserHomePath(str);
	//cout << "Home path    :" << str << endl << endl;
	getModuleName(str);
	cout << "Module    :" << str << endl << endl;

	vector<license::os::OsAdapterInfo> adapters;

	FUNCTION_RETURN result_adapterInfos = getAdapterInfos(adapters);
	if (result_adapterInfos != FUNC_RET_OK) {
		return result_adapterInfos;
	}
	if (adapters.size() == 0) {
		return FUNC_RET_NOT_AVAIL;
	}
	int cnt = 0;
	for (auto &it : adapters) {
		cnt++;

		cout << "MAC    :" << cnt << "th " << (int)it.mac_address[0] << "-" << (int)it.mac_address[1] << "-" << (int)it.mac_address[2] << "-" << (int)it.mac_address[3] << "-" << (int)it.mac_address[4] << endl << endl;
		cout << "MAC des:" << cnt << "th" << it.description << endl << endl;
		cout << "MAC ip :" << cnt << "th" << it.ipv4_address << endl << endl;
	}

	cout << "new machine id : " << machineid::machineHash() << endl << endl;
	return 0;
}
