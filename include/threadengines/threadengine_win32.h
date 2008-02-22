/*       +------------------------------------+
 *       | Inspire Internet Relay Chat Daemon |
 *       +------------------------------------+
 *
 *  InspIRCd: (C) 2002-2008 InspIRCd Development Team
 * See: http://www.inspircd.org/wiki/index.php/Credits
 *
 * This program is free but copyrighted software; see
 *            the file COPYING for details.
 *
 * ---------------------------------------------------
 */

#ifndef __THREADENGINE_WIN32THREAD__
#define __THREADENGINE_WIN32THREAD__

#include "inspircd_config.h"
#include "base.h"
#include "threadengine.h"

class InspIRCd;

class CoreExport Win32ThreadEngine : public ThreadEngine
{
 public:

	Win32ThreadEngine(InspIRCd* Instance);

	virtual ~Win32ThreadEngine();

	bool Mutex(bool enable);

	void Run();

	static DWORD WINAPI Entry(void* parameter);

	void Create(Thread* thread_to_init);

	void FreeThread(Thread* thread);

	const std::string GetName()
	{
		return "windows-thread";
	}
};

class CoreExport ThreadEngineFactory : public classbase
{
 public:
	ThreadEngine* Create(InspIRCd* ServerInstance)
	{
		return new Win32ThreadEngine(ServerInstance);
	}
};

#endif

