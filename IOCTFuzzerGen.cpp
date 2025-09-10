#include "Header.h"



vector<uint32_t> fuzzIOCTLMain() {
	return ioctlCodeGenerator();

}
DWORD ctlCodeGenerator(ioctlCodes& ioctlCode)
{

	return CTL_CODE(
		(ULONG)(ioctlCode.deviceType & 0xFFFF),
		(ULONG)(ioctlCode.function & 0xFFF),
		to_win_method(ioctlCode.method),
		to_win_access(ioctlCode.access)
	
	);
}
vector<uint32_t> ioctlCodeGenerator() {
	ioctlCodes ioctlcode;
	vector <uint32_t> ctlCodes;
	const access accesses[] = { access::any, access::read, access::write, access::readWrite };
	ctlCodes.reserve(16 * 256);
	for (uint16_t i = 0x9c30; i <= 0x9c50; i++) {
		for (uint16_t j = 0x900; j <= 0x982; j++) {
				ioctlcode = { i,j,method::buffer, access::any };
				ctlCodes.push_back(ctlCodeGenerator(ioctlcode));
			
		}
	}
	return ctlCodes;
}

