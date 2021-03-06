#include <base/hook/injectdll.h>
#include <base/path/self.h>
#include <debugger/protocol.h>

bool open_process_with_debugger(vscode::rprotocol& req, int pid)
{
	auto dir = base::path::self().remove_filename().remove_filename();
	if (!base::hook::injectdll(pid, dir / L"x86" / L"debugger-inject.dll", dir / L"x64" / L"debugger-inject.dll")) {
		return false;
	}
	return true;
}
