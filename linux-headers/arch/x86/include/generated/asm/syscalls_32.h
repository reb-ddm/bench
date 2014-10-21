__SYSCALL_I386(0, sys_restart_syscall, sys_restart_syscall)
__SYSCALL_I386(1, sys_exit, sys_exit)
__SYSCALL_I386(2, sys_fork, stub32_fork)
__SYSCALL_I386(3, sys_read, sys_read)
__SYSCALL_I386(4, sys_write, sys_write)
__SYSCALL_I386(5, sys_open, compat_sys_open)
__SYSCALL_I386(6, sys_close, sys_close)
__SYSCALL_I386(7, sys_waitpid, sys32_waitpid)
__SYSCALL_I386(8, sys_creat, sys_creat)
__SYSCALL_I386(9, sys_link, sys_link)
__SYSCALL_I386(10, sys_unlink, sys_unlink)
__SYSCALL_I386(11, sys_execve, stub32_execve)
__SYSCALL_I386(12, sys_chdir, sys_chdir)
__SYSCALL_I386(13, sys_time, compat_sys_time)
__SYSCALL_I386(14, sys_mknod, sys_mknod)
__SYSCALL_I386(15, sys_chmod, sys_chmod)
__SYSCALL_I386(16, sys_lchown16, sys_lchown16)
__SYSCALL_I386(18, sys_stat, sys_stat)
__SYSCALL_I386(19, sys_lseek, compat_sys_lseek)
__SYSCALL_I386(20, sys_getpid, sys_getpid)
__SYSCALL_I386(21, sys_mount, compat_sys_mount)
__SYSCALL_I386(22, sys_oldumount, sys_oldumount)
__SYSCALL_I386(23, sys_setuid16, sys_setuid16)
__SYSCALL_I386(24, sys_getuid16, sys_getuid16)
__SYSCALL_I386(25, sys_stime, compat_sys_stime)
__SYSCALL_I386(26, sys_ptrace, compat_sys_ptrace)
__SYSCALL_I386(27, sys_alarm, sys_alarm)
__SYSCALL_I386(28, sys_fstat, sys_fstat)
__SYSCALL_I386(29, sys_pause, sys_pause)
__SYSCALL_I386(30, sys_utime, compat_sys_utime)
__SYSCALL_I386(33, sys_access, sys_access)
__SYSCALL_I386(34, sys_nice, sys_nice)
__SYSCALL_I386(36, sys_sync, sys_sync)
__SYSCALL_I386(37, sys_kill, sys_kill)
__SYSCALL_I386(38, sys_rename, sys_rename)
__SYSCALL_I386(39, sys_mkdir, sys_mkdir)
__SYSCALL_I386(40, sys_rmdir, sys_rmdir)
__SYSCALL_I386(41, sys_dup, sys_dup)
__SYSCALL_I386(42, sys_pipe, sys_pipe)
__SYSCALL_I386(43, sys_times, compat_sys_times)
__SYSCALL_I386(45, sys_brk, sys_brk)
__SYSCALL_I386(46, sys_setgid16, sys_setgid16)
__SYSCALL_I386(47, sys_getgid16, sys_getgid16)
__SYSCALL_I386(48, sys_signal, sys_signal)
__SYSCALL_I386(49, sys_geteuid16, sys_geteuid16)
__SYSCALL_I386(50, sys_getegid16, sys_getegid16)
__SYSCALL_I386(51, sys_acct, sys_acct)
__SYSCALL_I386(52, sys_umount, sys_umount)
__SYSCALL_I386(54, sys_ioctl, compat_sys_ioctl)
__SYSCALL_I386(55, sys_fcntl, compat_sys_fcntl64)
__SYSCALL_I386(57, sys_setpgid, sys_setpgid)
__SYSCALL_I386(59, sys_olduname, sys_olduname)
__SYSCALL_I386(60, sys_umask, sys_umask)
__SYSCALL_I386(61, sys_chroot, sys_chroot)
__SYSCALL_I386(62, sys_ustat, compat_sys_ustat)
__SYSCALL_I386(63, sys_dup2, sys_dup2)
__SYSCALL_I386(64, sys_getppid, sys_getppid)
__SYSCALL_I386(65, sys_getpgrp, sys_getpgrp)
__SYSCALL_I386(66, sys_setsid, sys_setsid)
__SYSCALL_I386(67, sys_sigaction, compat_sys_sigaction)
__SYSCALL_I386(68, sys_sgetmask, sys_sgetmask)
__SYSCALL_I386(69, sys_ssetmask, sys_ssetmask)
__SYSCALL_I386(70, sys_setreuid16, sys_setreuid16)
__SYSCALL_I386(71, sys_setregid16, sys_setregid16)
__SYSCALL_I386(72, sys_sigsuspend, sys_sigsuspend)
__SYSCALL_I386(73, sys_sigpending, compat_sys_sigpending)
__SYSCALL_I386(74, sys_sethostname, sys_sethostname)
__SYSCALL_I386(75, sys_setrlimit, compat_sys_setrlimit)
__SYSCALL_I386(76, sys_old_getrlimit, compat_sys_old_getrlimit)
__SYSCALL_I386(77, sys_getrusage, compat_sys_getrusage)
__SYSCALL_I386(78, sys_gettimeofday, compat_sys_gettimeofday)
__SYSCALL_I386(79, sys_settimeofday, compat_sys_settimeofday)
__SYSCALL_I386(80, sys_getgroups16, sys_getgroups16)
__SYSCALL_I386(81, sys_setgroups16, sys_setgroups16)
__SYSCALL_I386(82, sys_old_select, compat_sys_old_select)
__SYSCALL_I386(83, sys_symlink, sys_symlink)
__SYSCALL_I386(84, sys_lstat, sys_lstat)
__SYSCALL_I386(85, sys_readlink, sys_readlink)
__SYSCALL_I386(86, sys_uselib, sys_uselib)
__SYSCALL_I386(87, sys_swapon, sys_swapon)
__SYSCALL_I386(88, sys_reboot, sys_reboot)
__SYSCALL_I386(89, sys_old_readdir, compat_sys_old_readdir)
__SYSCALL_I386(90, sys_old_mmap, sys32_mmap)
__SYSCALL_I386(91, sys_munmap, sys_munmap)
__SYSCALL_I386(92, sys_truncate, compat_sys_truncate)
__SYSCALL_I386(93, sys_ftruncate, compat_sys_ftruncate)
__SYSCALL_I386(94, sys_fchmod, sys_fchmod)
__SYSCALL_I386(95, sys_fchown16, sys_fchown16)
__SYSCALL_I386(96, sys_getpriority, sys_getpriority)
__SYSCALL_I386(97, sys_setpriority, sys_setpriority)
__SYSCALL_I386(99, sys_statfs, compat_sys_statfs)
__SYSCALL_I386(100, sys_fstatfs, compat_sys_fstatfs)
__SYSCALL_I386(101, sys_ioperm, sys_ioperm)
__SYSCALL_I386(102, sys_socketcall, compat_sys_socketcall)
__SYSCALL_I386(103, sys_syslog, sys_syslog)
__SYSCALL_I386(104, sys_setitimer, compat_sys_setitimer)
__SYSCALL_I386(105, sys_getitimer, compat_sys_getitimer)
__SYSCALL_I386(106, sys_newstat, compat_sys_newstat)
__SYSCALL_I386(107, sys_newlstat, compat_sys_newlstat)
__SYSCALL_I386(108, sys_newfstat, compat_sys_newfstat)
__SYSCALL_I386(109, sys_uname, sys_uname)
__SYSCALL_I386(110, sys_iopl, sys_iopl)
__SYSCALL_I386(111, sys_vhangup, sys_vhangup)
__SYSCALL_I386(113, sys_vm86old, sys32_vm86_warning)
__SYSCALL_I386(114, sys_wait4, compat_sys_wait4)
__SYSCALL_I386(115, sys_swapoff, sys_swapoff)
__SYSCALL_I386(116, sys_sysinfo, compat_sys_sysinfo)
__SYSCALL_I386(117, sys_ipc, compat_sys_ipc)
__SYSCALL_I386(118, sys_fsync, sys_fsync)
__SYSCALL_I386(119, sys_sigreturn, stub32_sigreturn)
__SYSCALL_I386(120, sys_clone, stub32_clone)
__SYSCALL_I386(121, sys_setdomainname, sys_setdomainname)
__SYSCALL_I386(122, sys_newuname, sys_newuname)
__SYSCALL_I386(123, sys_modify_ldt, sys_modify_ldt)
__SYSCALL_I386(124, sys_adjtimex, compat_sys_adjtimex)
__SYSCALL_I386(125, sys_mprotect, sys_mprotect)
__SYSCALL_I386(126, sys_sigprocmask, compat_sys_sigprocmask)
__SYSCALL_I386(128, sys_init_module, sys_init_module)
__SYSCALL_I386(129, sys_delete_module, sys_delete_module)
__SYSCALL_I386(131, sys_quotactl, sys32_quotactl)
__SYSCALL_I386(132, sys_getpgid, sys_getpgid)
__SYSCALL_I386(133, sys_fchdir, sys_fchdir)
__SYSCALL_I386(134, sys_bdflush, sys_bdflush)
__SYSCALL_I386(135, sys_sysfs, sys_sysfs)
__SYSCALL_I386(136, sys_personality, sys_personality)
__SYSCALL_I386(138, sys_setfsuid16, sys_setfsuid16)
__SYSCALL_I386(139, sys_setfsgid16, sys_setfsgid16)
__SYSCALL_I386(140, sys_llseek, sys_llseek)
__SYSCALL_I386(141, sys_getdents, compat_sys_getdents)
__SYSCALL_I386(142, sys_select, compat_sys_select)
__SYSCALL_I386(143, sys_flock, sys_flock)
__SYSCALL_I386(144, sys_msync, sys_msync)
__SYSCALL_I386(145, sys_readv, compat_sys_readv)
__SYSCALL_I386(146, sys_writev, compat_sys_writev)
__SYSCALL_I386(147, sys_getsid, sys_getsid)
__SYSCALL_I386(148, sys_fdatasync, sys_fdatasync)
__SYSCALL_I386(149, sys_sysctl, compat_sys_sysctl)
__SYSCALL_I386(150, sys_mlock, sys_mlock)
__SYSCALL_I386(151, sys_munlock, sys_munlock)
__SYSCALL_I386(152, sys_mlockall, sys_mlockall)
__SYSCALL_I386(153, sys_munlockall, sys_munlockall)
__SYSCALL_I386(154, sys_sched_setparam, sys_sched_setparam)
__SYSCALL_I386(155, sys_sched_getparam, sys_sched_getparam)
__SYSCALL_I386(156, sys_sched_setscheduler, sys_sched_setscheduler)
__SYSCALL_I386(157, sys_sched_getscheduler, sys_sched_getscheduler)
__SYSCALL_I386(158, sys_sched_yield, sys_sched_yield)
__SYSCALL_I386(159, sys_sched_get_priority_max, sys_sched_get_priority_max)
__SYSCALL_I386(160, sys_sched_get_priority_min, sys_sched_get_priority_min)
__SYSCALL_I386(161, sys_sched_rr_get_interval, compat_sys_sched_rr_get_interval)
__SYSCALL_I386(162, sys_nanosleep, compat_sys_nanosleep)
__SYSCALL_I386(163, sys_mremap, sys_mremap)
__SYSCALL_I386(164, sys_setresuid16, sys_setresuid16)
__SYSCALL_I386(165, sys_getresuid16, sys_getresuid16)
__SYSCALL_I386(166, sys_vm86, sys32_vm86_warning)
__SYSCALL_I386(168, sys_poll, sys_poll)
__SYSCALL_I386(170, sys_setresgid16, sys_setresgid16)
__SYSCALL_I386(171, sys_getresgid16, sys_getresgid16)
__SYSCALL_I386(172, sys_prctl, sys_prctl)
__SYSCALL_I386(173, sys_rt_sigreturn, stub32_rt_sigreturn)
__SYSCALL_I386(174, sys_rt_sigaction, compat_sys_rt_sigaction)
__SYSCALL_I386(175, sys_rt_sigprocmask, sys_rt_sigprocmask)
__SYSCALL_I386(176, sys_rt_sigpending, compat_sys_rt_sigpending)
__SYSCALL_I386(177, sys_rt_sigtimedwait, compat_sys_rt_sigtimedwait)
__SYSCALL_I386(178, sys_rt_sigqueueinfo, compat_sys_rt_sigqueueinfo)
__SYSCALL_I386(179, sys_rt_sigsuspend, sys_rt_sigsuspend)
__SYSCALL_I386(180, sys_pread64, sys32_pread)
__SYSCALL_I386(181, sys_pwrite64, sys32_pwrite)
__SYSCALL_I386(182, sys_chown16, sys_chown16)
__SYSCALL_I386(183, sys_getcwd, sys_getcwd)
__SYSCALL_I386(184, sys_capget, sys_capget)
__SYSCALL_I386(185, sys_capset, sys_capset)
__SYSCALL_I386(186, sys_sigaltstack, compat_sys_sigaltstack)
__SYSCALL_I386(187, sys_sendfile, compat_sys_sendfile)
__SYSCALL_I386(190, sys_vfork, stub32_vfork)
__SYSCALL_I386(191, sys_getrlimit, compat_sys_getrlimit)
__SYSCALL_I386(192, sys_mmap_pgoff, sys_mmap_pgoff)
__SYSCALL_I386(193, sys_truncate64, sys32_truncate64)
__SYSCALL_I386(194, sys_ftruncate64, sys32_ftruncate64)
__SYSCALL_I386(195, sys_stat64, sys32_stat64)
__SYSCALL_I386(196, sys_lstat64, sys32_lstat64)
__SYSCALL_I386(197, sys_fstat64, sys32_fstat64)
__SYSCALL_I386(198, sys_lchown, sys_lchown)
__SYSCALL_I386(199, sys_getuid, sys_getuid)
__SYSCALL_I386(200, sys_getgid, sys_getgid)
__SYSCALL_I386(201, sys_geteuid, sys_geteuid)
__SYSCALL_I386(202, sys_getegid, sys_getegid)
__SYSCALL_I386(203, sys_setreuid, sys_setreuid)
__SYSCALL_I386(204, sys_setregid, sys_setregid)
__SYSCALL_I386(205, sys_getgroups, sys_getgroups)
__SYSCALL_I386(206, sys_setgroups, sys_setgroups)
__SYSCALL_I386(207, sys_fchown, sys_fchown)
__SYSCALL_I386(208, sys_setresuid, sys_setresuid)
__SYSCALL_I386(209, sys_getresuid, sys_getresuid)
__SYSCALL_I386(210, sys_setresgid, sys_setresgid)
__SYSCALL_I386(211, sys_getresgid, sys_getresgid)
__SYSCALL_I386(212, sys_chown, sys_chown)
__SYSCALL_I386(213, sys_setuid, sys_setuid)
__SYSCALL_I386(214, sys_setgid, sys_setgid)
__SYSCALL_I386(215, sys_setfsuid, sys_setfsuid)
__SYSCALL_I386(216, sys_setfsgid, sys_setfsgid)
__SYSCALL_I386(217, sys_pivot_root, sys_pivot_root)
__SYSCALL_I386(218, sys_mincore, sys_mincore)
__SYSCALL_I386(219, sys_madvise, sys_madvise)
__SYSCALL_I386(220, sys_getdents64, compat_sys_getdents64)
__SYSCALL_I386(221, sys_fcntl64, compat_sys_fcntl64)
__SYSCALL_I386(224, sys_gettid, sys_gettid)
__SYSCALL_I386(225, sys_readahead, sys32_readahead)
__SYSCALL_I386(226, sys_setxattr, sys_setxattr)
__SYSCALL_I386(227, sys_lsetxattr, sys_lsetxattr)
__SYSCALL_I386(228, sys_fsetxattr, sys_fsetxattr)
__SYSCALL_I386(229, sys_getxattr, sys_getxattr)
__SYSCALL_I386(230, sys_lgetxattr, sys_lgetxattr)
__SYSCALL_I386(231, sys_fgetxattr, sys_fgetxattr)
__SYSCALL_I386(232, sys_listxattr, sys_listxattr)
__SYSCALL_I386(233, sys_llistxattr, sys_llistxattr)
__SYSCALL_I386(234, sys_flistxattr, sys_flistxattr)
__SYSCALL_I386(235, sys_removexattr, sys_removexattr)
__SYSCALL_I386(236, sys_lremovexattr, sys_lremovexattr)
__SYSCALL_I386(237, sys_fremovexattr, sys_fremovexattr)
__SYSCALL_I386(238, sys_tkill, sys_tkill)
__SYSCALL_I386(239, sys_sendfile64, sys_sendfile64)
__SYSCALL_I386(240, sys_futex, compat_sys_futex)
__SYSCALL_I386(241, sys_sched_setaffinity, compat_sys_sched_setaffinity)
__SYSCALL_I386(242, sys_sched_getaffinity, compat_sys_sched_getaffinity)
__SYSCALL_I386(243, sys_set_thread_area, sys_set_thread_area)
__SYSCALL_I386(244, sys_get_thread_area, sys_get_thread_area)
__SYSCALL_I386(245, sys_io_setup, compat_sys_io_setup)
__SYSCALL_I386(246, sys_io_destroy, sys_io_destroy)
__SYSCALL_I386(247, sys_io_getevents, compat_sys_io_getevents)
__SYSCALL_I386(248, sys_io_submit, compat_sys_io_submit)
__SYSCALL_I386(249, sys_io_cancel, sys_io_cancel)
__SYSCALL_I386(250, sys_fadvise64, sys32_fadvise64)
__SYSCALL_I386(252, sys_exit_group, sys_exit_group)
__SYSCALL_I386(253, sys_lookup_dcookie, compat_sys_lookup_dcookie)
__SYSCALL_I386(254, sys_epoll_create, sys_epoll_create)
__SYSCALL_I386(255, sys_epoll_ctl, sys_epoll_ctl)
__SYSCALL_I386(256, sys_epoll_wait, sys_epoll_wait)
__SYSCALL_I386(257, sys_remap_file_pages, sys_remap_file_pages)
__SYSCALL_I386(258, sys_set_tid_address, sys_set_tid_address)
__SYSCALL_I386(259, sys_timer_create, compat_sys_timer_create)
__SYSCALL_I386(260, sys_timer_settime, compat_sys_timer_settime)
__SYSCALL_I386(261, sys_timer_gettime, compat_sys_timer_gettime)
__SYSCALL_I386(262, sys_timer_getoverrun, sys_timer_getoverrun)
__SYSCALL_I386(263, sys_timer_delete, sys_timer_delete)
__SYSCALL_I386(264, sys_clock_settime, compat_sys_clock_settime)
__SYSCALL_I386(265, sys_clock_gettime, compat_sys_clock_gettime)
__SYSCALL_I386(266, sys_clock_getres, compat_sys_clock_getres)
__SYSCALL_I386(267, sys_clock_nanosleep, compat_sys_clock_nanosleep)
__SYSCALL_I386(268, sys_statfs64, compat_sys_statfs64)
__SYSCALL_I386(269, sys_fstatfs64, compat_sys_fstatfs64)
__SYSCALL_I386(270, sys_tgkill, sys_tgkill)
__SYSCALL_I386(271, sys_utimes, compat_sys_utimes)
__SYSCALL_I386(272, sys_fadvise64_64, sys32_fadvise64_64)
__SYSCALL_I386(274, sys_mbind, sys_mbind)
__SYSCALL_I386(275, sys_get_mempolicy, compat_sys_get_mempolicy)
__SYSCALL_I386(276, sys_set_mempolicy, sys_set_mempolicy)
__SYSCALL_I386(277, sys_mq_open, compat_sys_mq_open)
__SYSCALL_I386(278, sys_mq_unlink, sys_mq_unlink)
__SYSCALL_I386(279, sys_mq_timedsend, compat_sys_mq_timedsend)
__SYSCALL_I386(280, sys_mq_timedreceive, compat_sys_mq_timedreceive)
__SYSCALL_I386(281, sys_mq_notify, compat_sys_mq_notify)
__SYSCALL_I386(282, sys_mq_getsetattr, compat_sys_mq_getsetattr)
__SYSCALL_I386(283, sys_kexec_load, compat_sys_kexec_load)
__SYSCALL_I386(284, sys_waitid, compat_sys_waitid)
__SYSCALL_I386(286, sys_add_key, sys_add_key)
__SYSCALL_I386(287, sys_request_key, sys_request_key)
__SYSCALL_I386(288, sys_keyctl, sys_keyctl)
__SYSCALL_I386(289, sys_ioprio_set, sys_ioprio_set)
__SYSCALL_I386(290, sys_ioprio_get, sys_ioprio_get)
__SYSCALL_I386(291, sys_inotify_init, sys_inotify_init)
__SYSCALL_I386(292, sys_inotify_add_watch, sys_inotify_add_watch)
__SYSCALL_I386(293, sys_inotify_rm_watch, sys_inotify_rm_watch)
__SYSCALL_I386(294, sys_migrate_pages, sys_migrate_pages)
__SYSCALL_I386(295, sys_openat, compat_sys_openat)
__SYSCALL_I386(296, sys_mkdirat, sys_mkdirat)
__SYSCALL_I386(297, sys_mknodat, sys_mknodat)
__SYSCALL_I386(298, sys_fchownat, sys_fchownat)
__SYSCALL_I386(299, sys_futimesat, compat_sys_futimesat)
__SYSCALL_I386(300, sys_fstatat64, sys32_fstatat)
__SYSCALL_I386(301, sys_unlinkat, sys_unlinkat)
__SYSCALL_I386(302, sys_renameat, sys_renameat)
__SYSCALL_I386(303, sys_linkat, sys_linkat)
__SYSCALL_I386(304, sys_symlinkat, sys_symlinkat)
__SYSCALL_I386(305, sys_readlinkat, sys_readlinkat)
__SYSCALL_I386(306, sys_fchmodat, sys_fchmodat)
__SYSCALL_I386(307, sys_faccessat, sys_faccessat)
__SYSCALL_I386(308, sys_pselect6, compat_sys_pselect6)
__SYSCALL_I386(309, sys_ppoll, compat_sys_ppoll)
__SYSCALL_I386(310, sys_unshare, sys_unshare)
__SYSCALL_I386(311, sys_set_robust_list, compat_sys_set_robust_list)
__SYSCALL_I386(312, sys_get_robust_list, compat_sys_get_robust_list)
__SYSCALL_I386(313, sys_splice, sys_splice)
__SYSCALL_I386(314, sys_sync_file_range, sys32_sync_file_range)
__SYSCALL_I386(315, sys_tee, sys_tee)
__SYSCALL_I386(316, sys_vmsplice, compat_sys_vmsplice)
__SYSCALL_I386(317, sys_move_pages, compat_sys_move_pages)
__SYSCALL_I386(318, sys_getcpu, sys_getcpu)
__SYSCALL_I386(319, sys_epoll_pwait, sys_epoll_pwait)
__SYSCALL_I386(320, sys_utimensat, compat_sys_utimensat)
__SYSCALL_I386(321, sys_signalfd, compat_sys_signalfd)
__SYSCALL_I386(322, sys_timerfd_create, sys_timerfd_create)
__SYSCALL_I386(323, sys_eventfd, sys_eventfd)
__SYSCALL_I386(324, sys_fallocate, sys32_fallocate)
__SYSCALL_I386(325, sys_timerfd_settime, compat_sys_timerfd_settime)
__SYSCALL_I386(326, sys_timerfd_gettime, compat_sys_timerfd_gettime)
__SYSCALL_I386(327, sys_signalfd4, compat_sys_signalfd4)
__SYSCALL_I386(328, sys_eventfd2, sys_eventfd2)
__SYSCALL_I386(329, sys_epoll_create1, sys_epoll_create1)
__SYSCALL_I386(330, sys_dup3, sys_dup3)
__SYSCALL_I386(331, sys_pipe2, sys_pipe2)
__SYSCALL_I386(332, sys_inotify_init1, sys_inotify_init1)
__SYSCALL_I386(333, sys_preadv, compat_sys_preadv)
__SYSCALL_I386(334, sys_pwritev, compat_sys_pwritev)
__SYSCALL_I386(335, sys_rt_tgsigqueueinfo, compat_sys_rt_tgsigqueueinfo)
__SYSCALL_I386(336, sys_perf_event_open, sys_perf_event_open)
__SYSCALL_I386(337, sys_recvmmsg, compat_sys_recvmmsg)
__SYSCALL_I386(338, sys_fanotify_init, sys_fanotify_init)
__SYSCALL_I386(339, sys_fanotify_mark, compat_sys_fanotify_mark)
__SYSCALL_I386(340, sys_prlimit64, sys_prlimit64)
__SYSCALL_I386(341, sys_name_to_handle_at, sys_name_to_handle_at)
__SYSCALL_I386(342, sys_open_by_handle_at, compat_sys_open_by_handle_at)
__SYSCALL_I386(343, sys_clock_adjtime, compat_sys_clock_adjtime)
__SYSCALL_I386(344, sys_syncfs, sys_syncfs)
__SYSCALL_I386(345, sys_sendmmsg, compat_sys_sendmmsg)
__SYSCALL_I386(346, sys_setns, sys_setns)
__SYSCALL_I386(347, sys_process_vm_readv, compat_sys_process_vm_readv)
__SYSCALL_I386(348, sys_process_vm_writev, compat_sys_process_vm_writev)
__SYSCALL_I386(349, sys_kcmp, sys_kcmp)
__SYSCALL_I386(350, sys_finit_module, sys_finit_module)
__SYSCALL_I386(351, sys_sched_setattr, sys_sched_setattr)
__SYSCALL_I386(352, sys_sched_getattr, sys_sched_getattr)
__SYSCALL_I386(353, sys_renameat2, sys_renameat2)
__SYSCALL_I386(354, sys_seccomp, sys_seccomp)
__SYSCALL_I386(355, sys_getrandom, sys_getrandom)
__SYSCALL_I386(356, sys_memfd_create, sys_memfd_create)