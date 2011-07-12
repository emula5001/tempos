/**
 * Copyright (C) 2009 Renê de Souza Pinto
 * Tempos - Tempos is an Educational and multi purpose Operating System
 *
 * File: sched.c
 * Desc: The TempOS scheduler
 *
 * This file is part of TempOS.
 *
 * TempOS is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * TempOS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <tempos/sched.h>
#include <tempos/kernel.h>
#include <tempos/timer.h>
#include <tempos/jiffies.h>

/**
 * TempOS scheduler uses a round robin algorithm.
 * Yes, I know you are very surprised :-o
 */
uint32_t scheduler_quantum = HZ; /* 1 second << FOR TEST */


/**
 * init_sched
 *
 * Initialize the scheduler
 */
void init_scheduler(void)
{
	/* Register alarm to do task switch */
	if( !new_alarm((jiffies + scheduler_quantum), schedule, 0) ) {
		panic(KERN_CRIT "Could not install scheduler alarm.");
	}
}


/**
 * schedule
 *
 * Do a task switch
 */
/*int pg = 0;*/
void schedule(int p)
{
	/* Register alarm again */
	if( !new_alarm((jiffies + scheduler_quantum), schedule, p) ) {
		panic(KERN_CRIT "Could not install scheduler alarm.");
	/*} else {
		kprintf(KERN_CRITIC "HELLO! %d\n", pg++);*/
	}
}

