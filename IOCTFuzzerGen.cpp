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
	ctlCodes.reserve(16 * 16 * 4 * 1);
	for (uint16_t i = 0x8000; i <= 0x800F; i++) {
		for (uint16_t j = 0x800; j <= 0x80F; j++) {
			for (access acode : accesses) {
				ioctlcode = { i,j,method::buffer, acode };
				ctlCodes.push_back(ctlCodeGenerator(ioctlcode));
			}
		}
	}
	return ctlCodes;
}