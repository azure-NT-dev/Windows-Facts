#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <thread>
#include <chrono>
#include <windows.h>

void typewrite(const std::string& text, int delay_ms = 15) {
    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
    }
}

std::string get_clean_terminal_name() {
    char* prompt_env = std::getenv("PROMPT");
    char* ps_module_env = std::getenv("PSModulePath");

    if (ps_module_env != nullptr && prompt_env == nullptr) {
        return "powershell.exe";
    }
    if (prompt_env != nullptr) {
        return "cmd.exe";
    }
    return "WindowsTerminal.exe";
}

int main() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::string user_input = "";

    std::cout << "\033[2J\033[1;1H\033[0m";

    std::cout << "\033[1;36m====================================================\033[0m\n";
    std::cout << "\033[1;37m        RANDOM FACTS GAME: WINDOWS EDITION          \033[0m\n";
    std::cout << "\033[1;36m====================================================\033[0m\n\n";

    std::string terminal_env = get_clean_terminal_name();
    typewrite("[Info] \"" + terminal_env + "\" spawned.\n");
    typewrite("[Info] Getting Ready...\n\n");

    while (true) {
        std::cout << "\033[1;32m[Input] Enter a year/keyword to analyze (or 'exit' to quit): \033[0m";
        std::cin >> user_input;

        if (user_input == "exit" || user_input == "quit") {
            std::cout << "\n";
            typewrite("[Info] Terminating archive session...\n");
            break;
        }

        std::cout << "\n\033[1;33m[Processing] Searching internal databases...\033[0m\n";

        std::string spinner = "|/-\\";
        for (int i = 0; i < 20; ++i) {
            std::cout << "\r[ " << spinner[i % 4] << " ] Querying timeline vector: " << (i * 5) << "%" << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(40));
        }
        std::cout << "\r[ + ] Database retrieval complete: 100%       \033[0m\n\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(200));

        std::cout << "\033[1;37m";

        int input_year = 0;
        bool is_numeric = false;
        try {
            input_year = std::stoi(user_input);
            is_numeric = true;
        }
        catch (...) {
            is_numeric = false;
        }

        if (is_numeric && (input_year < 1985 || input_year > 2026)) {
            std::cout << "\033[1;35m";
            typewrite(">> Time Anomaly Detected: Are you from the future (or distant past)?\n");
            typewrite("   What kind of Windows did they release in " + user_input + "?\n");
            typewrite("   Is NT finally bumped to 11.0?\n");
            std::cout << "\033[0m";
        }
        else if (user_input == "1985") {
            typewrite(">> 1985 Milestone: The Genesis of Windows 1.0\n");
            typewrite("   Released November 20, 1985. Microsoft's first 16-bit GUI operating environment\n");
            typewrite("   running on top of MS-DOS, introducing tiled windows and mouse interaction.\n");
        }
        else if (user_input == "1987") {
            typewrite(">> 1987 Milestone: Overlapping Windows (Windows 2.0 / 2.03)\n");
            typewrite("   Released December 9, 1987. Added overlapping windows, desktop icons, keyboard\n");
            typewrite("   shortcuts, and early support for VGA graphics and early Word/Excel builds.\n");
        }
        else if (user_input == "1988") {
            typewrite(">> 1988 Milestone: Processor Optimizations (Windows 2.1x / 286 / 386)\n");
            typewrite("   Released May 27, 1988. Introduced custom builds taking direct advantage of\n");
            typewrite("   Intel 80286 and 80386 protected mode memory capabilities.\n");
        }
        else if (user_input == "1990") {
            typewrite(">> 1990 Milestone: Commercial Breakthrough (Windows 3.0)\n");
            typewrite("   Released May 22, 1990. Redesigned user interface featuring Program Manager,\n");
            typewrite("   File Manager, 16-color graphics support, and virtual memory capabilities.\n");
        }
        else if (user_input == "1992") {
            typewrite(">> 1992 Milestone: Mainstream Adoption (Windows 3.1 / Workgroups)\n");
            typewrite("   Released April 6, 1992. Dropped Real Mode support, introduced native TrueType fonts,\n");
            typewrite("   and debuted peer-to-peer networking extensions in Windows for Workgroups 3.1.\n");
        }
        else if (user_input == "1993") {
            typewrite(">> 1993 Milestone: The Birth of Windows NT 3.1 & Windows 3.11\n");
            typewrite("   July 27, 1993 saw the release of Windows NT 3.1, engineered by Dave Cutler as a true\n");
            typewrite("   32-bit preemptive OS. December 1993 brought Windows 3.11 with bug fixes and network enhancements.\n");
        }
        else if (user_input == "1994") {
            typewrite(">> 1994 Milestone: Enterprise Expansion (Windows NT 3.5)\n");
            typewrite("   Released September 21, 1994. Focused on higher system performance, Winsock TCP/IP support,\n");
            typewrite("   and integrated VFAT file system handling.\n");
        }
        else if (user_input == "1995") {
            typewrite(">> 1995 Milestone: Windows 95 & Windows NT 3.51\n");
            typewrite("   August 24, 1995 brought Windows 95, introducing the iconic Start Menu, Taskbar, and 32-bit API.\n");
            typewrite("   May 30, 1995 saw NT 3.51 deployed with PowerPC architecture compatibility.\n");
        }
        else if (user_input == "1996") {
            typewrite(">> 1996 Milestone: Windows NT 4.0 & Windows CE 1.0\n");
            typewrite("   Released July 24, 1996. Windows NT 4.0 brought the Windows 95 UI shell to the rock-solid\n");
            typewrite("   NT kernel. Windows CE 1.0 was also introduced for handheld embedded devices.\n");
        }
        else if (user_input == "1998") {
            typewrite(">> 1998 Milestone: Consumer Web & Hardware Polish (Windows 98)\n");
            typewrite("   Released June 25, 1998. Heavily integrated Internet Explorer 4, native USB hub/device\n");
            typewrite("   support, ACPI power management, and the FAT32 file system standard.\n");
        }
        else if (user_input == "1999") {
            typewrite(">> 1999 Milestone: Stability Update (Windows 98 Second Edition)\n");
            typewrite("   Released May 5, 1999. Fixed major driver bugs, updated Internet Explorer 5, and introduced\n");
            typewrite("   Internet Connection Sharing (ICS).\n");
        }
        else if (user_input == "2000") {
            typewrite(">> 2000 Milestone: The Dual Releases (Windows 2000 & Windows Me)\n");
            typewrite("   Windows 2000 (Feb 17) delivered NT 5.0 stability with NTFS 3.0 and Active Directory.\n");
            typewrite("   Windows Me (Sep 14) marked the final legacy MS-DOS-based release for home consumers.\n");
        }
        else if (user_input == "2001") {
            typewrite(">> 2001 Milestone: Core Architecture Merger (Windows XP)\n");
            typewrite("   Released October 25, 2001. Unified consumer desktop UI with enterprise NT stability (NT 5.1),\n");
            typewrite("   permanently retiring the legacy MS-DOS monolithic codebase.\n");
        }
        else if (user_input == "2003") {
            typewrite(">> 2003 Milestone: Enterprise Infrastructure (Windows Server 2003)\n");
            typewrite("   Released April 24, 2003. Built on NT 5.2, bringing major security hardening (IIS 6.0),\n");
            typewrite("   Group Policy enhancements, and early x64 architecture support.\n");
        }
        else if (user_input == "2006" || user_input == "2007") {
            typewrite(">> 2006-2007 Milestone: Visual Overhaul (Windows Vista)\n");
            typewrite("   Released to business in Nov 2006 and retail Jan 30, 2007. Introduced Aero Glass UI, UAC,\n");
            typewrite("   Windows Search, and a rewritten audio/networking driver stack.\n");
        }
        else if (user_input == "2009") {
            typewrite(">> 2009 Milestone: Refinement and Stability (Windows 7)\n");
            typewrite("   Released October 22, 2009. Optimized Vista's architecture, introduced the revamped 'Superbar',\n");
            typewrite("   Libraries, and substantially lower system resource overhead.\n");
        }
        else if (user_input == "2012") {
            typewrite(">> 2012 Milestone: Touch-Centric UI (Windows 8)\n");
            typewrite("   Released October 26, 2012. Replaced the classic Start Menu with the 'Metro' Start Screen,\n");
            typewrite("   tailored for touchscreens, native USB 3.0, and fast startup initialization.\n");
        }
        else if (user_input == "2013") {
            typewrite(">> 2013 Milestone: Desktop Restoration (Windows 8.1)\n");
            typewrite("   Released October 17, 2013. Restored the visible Start Button, added direct boot-to-desktop,\n");
            typewrite("   and polished multi-tasking snapped window configurations.\n");
        }
        else if (user_input == "2015") {
            typewrite(">> 2015 Milestone: Windows-as-a-Service (Windows 10)\n");
            typewrite("   Released July 29, 2015. Restored the hybrid Start Menu, added virtual desktops, Microsoft Edge,\n");
            typewrite("   and shifted Windows onto a continuous rolling update model.\n");
        }
        else if (user_input == "2021") {
            typewrite(">> 2021 Milestone: Modern UI & Hardware Rules (Windows 11)\n");
            typewrite("   Released October 5, 2021. Centered taskbar redesign, Snap Layouts, DirectStorage, Auto-HDR,\n");
            typewrite("   and strict hardware security requirements (TPM 2.0 & UEFI Secure Boot).\n");
        }
        else if (user_input == "KeBugCheckEx") {
            std::cout << "\033[1;31m";
            typewrite(">> Okay, that was unexpected, alright time to explain what this function does\n\n");
            typewrite("   Inside the core platform layer, calling KeBugCheckEx immediately brings down\n");
            typewrite("   the entire operating subsystem architecture. This function stops all execution,\n");
            typewrite("   unloads active driver arrays, and paints the fatal Blue Screen of Death (BSOD).\n");
            typewrite("   It is the kernel's self-defense switch when it hits data corruption it cannot clear.\n");
            std::cout << "\033[0m";
        }
        else if (user_input == "ntoskrnl.exe") {
            std::cout << "\033[1;31m";
            typewrite(">> Oh, hey thats the kernel...\n\n");
            typewrite("   Target Engine: ntoskrnl.exe (Windows NT Operating System Kernel executable)\n");
            typewrite("   This is the core binary responsible for hardware abstraction, process and thread management,\n");
            typewrite("   memory virtualization, and host system execution in the NT architecture.\n");
            std::cout << "\033[0m";
        }
        else {
            std::string non_exact_options[] = {
                "No specific Windows OS release milestone registered for this exact fiscal timeline.",
                "Historical ledger records normal hardware distribution cycles during this calendar block.",
                "Standard business maintenance and localized service packs were deployed in this timeframe.",
                "System database does not register a critical kernel iteration within this specified calendar window."
            };
            typewrite(">> Notice: " + non_exact_options[std::rand() % 4] + "\n");
        }
        std::cout << "\033[0m\n";
    }

    std::cout << "\n\033[1;90m[Operation complete. Press Enter to close window...]\033[0m";
    std::cin.ignore();
    std::cin.get();

    return 0;
}