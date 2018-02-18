#NO_APP
.text
LC0:
	.ascii "w\0"
LC1:
	.ascii "CON:32/32/640/240/MyThread/CLOSE/WAIT\0"
LC2:
	.ascii "This console is used by the created thread for output\12\0"
	.even
.globl ___8MyThread
___8MyThread:
	link a5,#-104
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-100)
	pea 4096:w
	clrl sp@-
	movel a5@(8),sp@-
	jbsr ___6ThreadQ26Thread8PriorityUl
	movel a5@(-100),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L148,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a5@(-104)
	jra L147
	.even
L148:
	movel a5@(-100),a0
	addql #4,a0
	movel a0,a5@(-104)
	jra L145
	.even
L147:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(8),a0
	pea a0@(96)
	jbsr ___17ThreadRunObserver
	movel a5@(-104),a1
	movel a1@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L154,a5@(-36)
	movel sp,a5@(-32)
	jra L153
	.even
L154:
	movel a5@(-100),a0
	addql #4,a0
	movel a0,a5@(-104)
	jra L151
	.even
L153:
	lea a5@(-48),a0
	movel a5@(-104),a1
	movel a0,a1@
	movel a5@(8),a1
	movel #___vt_8MyThread$17ThreadRunObserver,a1@(96)
	movel #___vt_8MyThread,a1@
	moveq #2,d0
	movel d0,a1@(104)
	clrl a1@(108)
	clrb a1@(112)
	addw #12,sp
	movel #LC0,sp@
	pea LC1
	jbsr _fopen
	movel a5@(8),a0
	movel d0,a0@(100)
	addql #8,sp
	jeq L155
	pea LC2
	movel d0,sp@-
	jbsr _fprintf
	movel a5@(8),a1
	movel a1@(100),sp@-
	jbsr _fflush
	addw #12,sp
L155:
	movel a5@(-104),a1
	movel a1@,a0
	movel a0@,a1@
	movel a1@,a0
	movel a0@,a1@
	movel a5@(8),d0
	jra L166
	.even
L151:
	movel a5@(-104),a0
	movel a0@,a5@(-72)
	clrl a5@(-68)
	movel a5,a5@(-64)
	movel #L160,a5@(-60)
	movel sp,a5@(-56)
	jra L159
	.even
L160:
	jra L167
	.even
L159:
	lea a5@(-72),a0
	movel a5@(-104),a1
	movel a0,a1@
	clrl sp@-
	movel a5@(8),a1
	pea a1@(96)
	jbsr __$_17ThreadRunObserver
	movel a5@(-100),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	addql #8,sp
	jbsr ___sjthrow
	.even
L145:
	movel a5@(-104),a0
	movel a0@,a5@(-96)
	clrl a5@(-92)
	movel a5,a5@(-88)
	movel #L164,a5@(-84)
	movel sp,a5@(-80)
	jra L163
	.even
L164:
	jra L168
	.even
L163:
	lea a5@(-96),a0
	movel a5@(-104),a1
	movel a0,a1@
	clrl sp@-
	movel a5@(8),sp@-
	jbsr __$_6Thread
	movel a5@(-100),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	addql #8,sp
	jbsr ___sjthrow
	.even
L167:
L157:
	jbsr ___terminate
	.even
L168:
L161:
	jbsr ___terminate
	.even
L166:
	moveml a5@(-216),#0x5cfc
	fmovem a5@(-176),#0x3f
	unlk a5
	rts
LC3:
	.ascii "\12Bye!\12\0"
	.even
.globl __$_8MyThread
__$_8MyThread:
	movel a2,sp@-
	movel sp@(8),a2
	movel #___vt_8MyThread$17ThreadRunObserver,a2@(96)
	movel #___vt_8MyThread,a2@
	movel a2,sp@-
	jbsr _hasStarted__C6Thread
	addql #4,sp
	tstb d0
	jeq L170
	movel a2,sp@-
	jbsr _stop__6Thread
	addql #4,sp
L170:
	movel a2@(100),d0
	jeq L172
	pea LC3
	movel d0,sp@-
	jbsr _fprintf
	movel a2@(100),sp@-
	jbsr _fclose
	addw #12,sp
L172:
	clrl sp@-
	pea a2@(96)
	jbsr __$_17ThreadRunObserver
	movel sp@(20),sp@-
	movel a2,sp@-
	jbsr __$_6Thread
	addw #16,sp
	movel sp@+,a2
	rts
LC4:
	.ascii "MyThread::run() invoked OK\12\0"
LC5:
	.ascii "Sleeping for 2000ms...\0"
LC6:
	.ascii "OK\12\0"
LC7:
	.ascii "interrupted by wake()\12\0"
LC8:
	.ascii "interrupted by stop()\12\0"
LC9:
	.ascii "interrupted by system break\12\0"
LC10:
	.ascii "interrupted by user signal\12\0"
LC11:
	.ascii "interrupted by ~Thread()\12\0"
LC12:
	.ascii "interrupted by unknown\12\0"
LC13:
	.ascii "\12MyThread::run() completed\12\0"
	.even
.globl _run__8MyThread
_run__8MyThread:
	moveml #0x3c,sp@-
	movel sp@(20),a4
	pea a4@(96)
	movel a4,sp@-
	jbsr _setRunObserver__6ThreadP17ThreadRunObserver
	addql #8,sp
	tstl a4@(100)
	jne L174
	jbsr _throwNullPointer
L174:
	pea LC4
	movel a4@(100),sp@-
	lea _fprintf,a3
	jbsr a3@
	movel a4@(100),sp@-
	lea _fflush,a2
	jbsr a2@
	movel a4,sp@-
	jbsr _enableLowLevelExceptions__6Thread
	addw #16,sp
	lea _stopRequested__C6Thread,a5
	jra L175
	.even
L177:
	pea LC5
	movel a4@(100),sp@-
	jbsr a3@
	movel a4@(100),sp@-
	jbsr a2@
	addqw #8,sp
	movel #12,sp@
	pea 2000:w
	movel a4,sp@-
	jbsr _suspend__6ThreadUlUl
	addw #12,sp
	moveq #7,d1
	cmpl d0,d1
	jcs L178
LI187:
	movew pc@(L187-LI187-2:b,d0:l:2),d0
	jmp pc@(2,d0:w)
	.even
L187:
	.word L179-L187
	.word L180-L187
	.word L181-L187
	.word L184-L187
	.word L182-L187
	.word L183-L187
	.word L178-L187
	.word L185-L187
	.even
L179:
	pea LC6
	jra L191
	.even
L180:
	pea LC7
	jra L191
	.even
L181:
	pea LC8
	jra L191
	.even
L182:
	pea LC9
	jra L191
	.even
L183:
	pea LC10
	jra L191
	.even
L184:
	pea LC11
	jra L191
	.even
L185:
	pea LC12
L191:
	movel a4@(100),sp@-
	jbsr a3@
	addql #8,sp
L178:
	movel a4@(100),sp@-
	jbsr a2@
	addql #4,sp
	tstb a4@(112)
	jeq L175
	clrb a4@(112)
	movel a4@(104),d1
	divsl a4@(108),d1
	movel d1,a4@(104)
L175:
	movel a4,sp@-
	jbsr a5@
	addql #4,sp
	tstb d0
	jeq L177
	pea LC13
	movel a4@(100),sp@-
	jbsr a3@
	clrl d0
	addql #8,sp
	moveml sp@+,#0x3c00
	rts
LC14:
	.ascii "*** Observer: Thread %s returned %d\12\0"
	.even
.globl _notifyReturned__8MyThreadP6Threadl
_notifyReturned__8MyThreadP6Threadl:
	movel sp@(12),sp@-
	movel sp@(12),sp@-
	jbsr _getResourceName__C6Thread
	movel d0,sp@
	pea LC14
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addw #16,sp
	rts
	nop
LC15:
	.ascii "exception\0"
LC16:
	.ascii "*** Observer: Thread %s threw uncaught %s\12\0"
	.even
.globl _notifyThrown__8MyThreadP6ThreadPC12RuntimeError
_notifyThrown__8MyThreadP6ThreadPC12RuntimeError:
	movel sp@(12),a1
	tstl a1
	jeq L195
	movel a1@,a0
	movel a1,sp@-
	movel a0@(12),a0
	jbsr a0@
	addql #4,sp
	jra L196
	.even
L195:
	movel #LC15,d0
L196:
	movel d0,sp@-
	movel sp@(12),sp@-
	jbsr _getResourceName__C6Thread
	movel d0,sp@
	pea LC16
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addw #16,sp
	rts
	nop
	.even
.globl _createInstance__11Application
_createInstance__11Application:
	link a5,#-60
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-56)
	pea 10:w
	jbsr ___builtin_new
	movel d0,a5@(-52)
	movel a5@(-56),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L202,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a5@(-60)
	jra L201
	.even
L202:
	movel a5@(-56),a0
	addql #4,a0
	movel a0,a5@(-60)
	jra L199
	.even
L201:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(-52),sp@-
	jbsr ___13ThreadTestApp
	movel a5@(-60),a1
	movel a1@,a0
	movel a0@,a1@
	addql #8,sp
	jra L198
	.even
L199:
	movel a5@(-60),a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L208,a5@(-36)
	movel sp,a5@(-32)
	jra L207
	.even
L208:
	jra L213
	.even
L207:
	lea a5@(-48),a0
	movel a5@(-60),a1
	movel a0,a1@
	moveq #1,d0
	jeq L210
	movel a5@(-52),sp@-
	jbsr ___builtin_delete
	addql #4,sp
L210:
	movel a5@(-56),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L213:
L205:
	jbsr ___terminate
	.even
L198:
	moveml a5@(-172),#0x5cfc
	fmovem a5@(-132),#0x3f
	unlk a5
	rts
	.even
.globl _destroyInstance__11ApplicationP11Application
_destroyInstance__11ApplicationP11Application:
	movel sp@(4),a1
	tstl a1
	jeq L219
	movel a1@,a0
	pea 3:w
	movel a1,sp@-
	movel a0@(16),a0
	jbsr a0@
	addql #8,sp
L219:
	rts
	nop
LC17:
	.ascii "Created ThreadTestApp\12\0"
	.even
.globl ___13ThreadTestApp
___13ThreadTestApp:
	link a5,#-112
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-106)
	movel a5@(8),sp@-
	jbsr ___11Application
	movel a5@(-106),a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L224,a5@(-12)
	movel sp,a5@(-8)
	movel a0,a5@(-110)
	jra L223
	.even
L224:
	movel a5@(-106),a0
	addql #4,a0
	movel a0,a5@(-110)
	jra L221
	.even
L223:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(8),a0
	movel #___vt_13ThreadTestApp,a0@
	clrl a0@(6)
	movel #114,sp@
	jbsr ___builtin_new
	movel d0,a5@(-100)
	moveb #1,a5@(-101)
	movel a5@(-110),a1
	movel a1@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L228,a5@(-36)
	movel sp,a5@(-32)
	jra L227
	.even
L228:
	movel a5@(-106),a0
	addql #4,a0
	movel a0,a5@(-110)
	jra L225
	.even
L227:
	lea a5@(-48),a0
	movel a5@(-110),a1
	movel a0,a1@
	movel a5@(-100),sp@-
	jbsr ___8MyThread
	clrb a5@(-101)
	movel a5@(8),a1
	movel d0,a1@(6)
	movel a5@(-110),a1
	movel a1@,a0
	movel a0@,a1@
	addqw #4,sp
	movel #LC17,sp@
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addql #8,sp
	movel a5@(-110),a1
	movel a1@,a0
	movel a0@,a1@
	movel a5@(8),d0
	jra L243
	.even
L225:
	movel a5@(-110),a0
	movel a0@,a5@(-72)
	clrl a5@(-68)
	movel a5,a5@(-64)
	movel #L235,a5@(-60)
	movel sp,a5@(-56)
	jra L234
	.even
L235:
	jra L244
	.even
L234:
	lea a5@(-72),a0
	movel a5@(-110),a1
	movel a0,a1@
	tstb a5@(-101)
	jeq L237
	movel a5@(-100),sp@-
	jbsr ___builtin_delete
	addql #4,sp
L237:
	movel a5@(-106),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	jbsr ___sjthrow
	.even
L221:
	movel a5@(-110),a1
	movel a1@,a5@(-96)
	clrl a5@(-92)
	movel a5,a5@(-88)
	movel #L241,a5@(-84)
	movel sp,a5@(-80)
	jra L240
	.even
L241:
	jra L245
	.even
L240:
	lea a5@(-96),a1
	movel a5@(-110),a0
	movel a1,a0@
	clrl sp@-
	movel a5@(8),sp@-
	jbsr __$_11Application
	movel a5@(-106),a1
	addql #4,a1
	movel a1@,a0
	movel a0@,a1@
	addql #8,sp
	jbsr ___sjthrow
	.even
L244:
L232:
	jbsr ___terminate
	.even
L245:
L238:
	jbsr ___terminate
	.even
L243:
	moveml a5@(-224),#0x5cfc
	fmovem a5@(-184),#0x3f
	unlk a5
	rts
LC18:
	.ascii "Main Program Uptime:%3lu days %02lu hours %02lu mins %02lu secs %03lu millis\12\0"
LC19:
	.ascii "Destroyed ThreadTestApp\12\0"
	.even
.globl __$_13ThreadTestApp
__$_13ThreadTestApp:
	addw #-12,sp
	movel a2,sp@-
	movel d2,sp@-
	movel sp@(24),a2
	movel #___vt_13ThreadTestApp,a2@
	jbsr _getCurrent__6Thread
	movel d0,sp@-
	moveq #12,d2
	addl sp,d2
	movel d2,a1
	jbsr _getUptime__C6Thread
	movel d2,sp@-
	jbsr _millisecs__C8Interval
	movel d0,sp@-
	movel d2,sp@-
	jbsr _secs__C8Interval
	movel d0,sp@
	movel d2,sp@-
	jbsr _mins__C8Interval
	movel d0,sp@
	movel d2,sp@-
	jbsr _hours__C8Interval
	movel d0,sp@
	movel d2,sp@-
	jbsr _days__C8Interval
	movel d0,sp@
	pea LC18
	jbsr _printf
	addw #32,sp
	movel a2@(6),a1
	tstl a1
	jeq L248
	movel a1@,a0
	pea 3:w
	movel a1,sp@-
	movel a0@(16),a0
	jbsr a0@
	addql #8,sp
L248:
	pea LC19
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addql #8,sp
	movel sp@(28),sp@-
	movel a2,sp@-
	jbsr __$_11Application
	addql #8,sp
	movel sp@+,d2
	movel sp@+,a2
	addw #12,sp
	rts
LC20:
	.ascii "\12Created Thread %s, child of %s\12\12\0"
LC21:
	.ascii "Choose method\12"
	.ascii "1 start()\12"
	.ascii "2 stop()\12"
	.ascii "3 wake()\12"
	.ascii "4 getUpTime()\12"
	.ascii "5 set boobytrap\12Q Quit\0"
LC22:
	.ascii "Unable to complete operation, caught %s\12\0"
LC23:
	.ascii "Unable to complete operation, caught an exception\12\0"
LC24:
	.ascii "Bye!\0"
	.even
.globl _run__13ThreadTestApp
_run__13ThreadTestApp:
	link a5,#-140
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,a5@(-134)
	movel a5@(8),a0
	tstl a0@(6)
	jne L251
	movel d0,a1
	addql #4,a1
	movel a1,a5@(-138)
	jbsr _throwNullPointer
L251:
	movel a5@(8),a0
	movel a0@(6),sp@-
	movel a5@(-134),a1
	addql #4,a1
	movel a1,a5@(-138)
	jbsr _getParent__C6Thread
	movel d0,sp@-
	jbsr _getResourceName__C6Thread
	movel d0,sp@-
	movel a5@(8),a0
	movel a0@(6),sp@-
	jbsr _getResourceName__C6Thread
	movel d0,sp@
	pea LC20
	jbsr _printf
	pea LC21
	jbsr _puts
	clrb a5@(-121)
	addw #24,sp
	.even
L254:
	movel a5@(-138),a1
	movel a1@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L258,a5@(-12)
	movel sp,a5@(-8)
	jra L257
	.even
L258:
	jra L291
	.even
L257:
	lea a5@(-24),a1
	movel a5@(-138),a0
	movel a1,a0@
	jbsr _getchar
	moveq #-49,d1
	addl d1,d0
	moveq #64,d1
	cmpl d0,d1
	jcs L259
LI268:
	movew pc@(L268-LI268-2:b,d0:l:2),d0
	jmp pc@(2,d0:w)
	.even
L268:
	.word L260-L268
	.word L261-L268
	.word L262-L268
	.word L263-L268
	.word L264-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L266-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L259-L268
	.word L266-L268
	.even
L260:
	movel a5@(8),a0
	movel a0@(6),sp@-
	jbsr _start__6Thread
	addql #4,sp
	jra L259
	.even
L261:
	movel a5@(8),a1
	movel a1@(6),sp@-
	jbsr _stop__6Thread
	addql #4,sp
	jra L259
	.even
L262:
	movel a5@(8),a0
	movel a0@(6),sp@-
	jbsr _wake__6Thread
	addql #4,sp
	jra L259
	.even
L263:
	movel a5@(8),sp@-
	jbsr _showUptime__13ThreadTestApp
	addql #4,sp
	jra L259
	.even
L264:
	movel a5@(8),a1
	movel a1@(6),sp@-
	jbsr _setTrap__8MyThread
	addql #4,sp
	jra L259
	.even
L266:
	moveb #1,a5@(-121)
L259:
	movel a5@(-138),a1
	movel a1@,a0
	movel a0@,a1@
L252:
	tstb a5@(-121)
	jeq L254
	pea LC24
	jbsr _puts
	clrl d0
	addql #4,sp
	jra L250
	.even
L291:
L255:
	pea ___tf12RuntimeError
	jbsr ___eh_rtime_match
	addql #4,sp
	tstl d0
	jeq L275
	jbsr ___start_cp_handler
	movel d0,a5@(-126)
	movel a5@(-138),a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L274,a5@(-36)
	movel sp,a5@(-32)
	jra L273
	.even
L274:
	jra L292
	.even
L273:
	lea a5@(-48),a0
	movel a5@(-138),a1
	movel a0,a1@
	movel a5@(-126),a1
	movel a1@(8),a0
	movel a0@,a1
	movel a0,sp@-
	movel a1@(12),a0
	jbsr a0@
	movel d0,sp@-
	pea LC22
	jbsr _printf
	movel a5@(-138),a1
	movel a1@,a0
	movel a0@,a1@
	addqw #8,sp
	movel a5@(-126),sp@
	jra L293
	.even
L275:
	jbsr ___start_cp_handler
	movel d0,a5@(-130)
	movel a5@(-138),a0
	movel a0@,a5@(-72)
	clrl a5@(-68)
	movel a5,a5@(-64)
	movel #L279,a5@(-60)
	movel sp,a5@(-56)
	jra L278
	.even
L279:
	jra L294
	.even
L278:
	lea a5@(-72),a0
	movel a5@(-138),a1
	movel a0,a1@
	pea LC23
	jbsr _printf
	movel a5@(-138),a1
	movel a1@,a0
	movel a0@,a1@
	movel a5@(-130),sp@
L293:
	jbsr ___cp_pop_exception
	addql #4,sp
	jra L252
	.even
L292:
L271:
	movel a5@(-138),a0
	movel a0@,a5@(-96)
	clrl a5@(-92)
	movel a5,a5@(-88)
	movel #L284,a5@(-84)
	movel sp,a5@(-80)
	jra L283
	.even
L284:
	jra L295
	.even
L283:
	lea a5@(-96),a0
	movel a5@(-138),a1
	movel a0,a1@
	movel a5@(-126),sp@-
	jbsr ___cp_pop_exception
	movel a5@(-138),a1
	movel a1@,a0
	movel a0@,a1@
	addql #4,sp
	jbsr ___sjthrow
	.even
L294:
L276:
	movel a5@(-138),a0
	movel a0@,a5@(-120)
	clrl a5@(-116)
	movel a5,a5@(-112)
	movel #L288,a5@(-108)
	movel sp,a5@(-104)
	jra L287
	.even
L288:
	jra L296
	.even
L287:
	lea a5@(-120),a0
	movel a5@(-138),a1
	movel a0,a1@
	movel a5@(-130),sp@-
	jbsr ___cp_pop_exception
	movel a5@(-138),a1
	movel a1@,a0
	movel a0@,a1@
	addql #4,sp
	jbsr ___sjthrow
	.even
L295:
L281:
	jbsr ___terminate
	.even
L296:
L285:
	jbsr ___terminate
	.even
L250:
	moveml a5@(-252),#0x5cfc
	fmovem a5@(-212),#0x3f
	unlk a5
	rts
LC25:
	.ascii "Uptime:%3lu days %02lu hours %02lu mins %02lu secs %03lu millis\12\0"
	.even
.globl _showUptime__13ThreadTestApp
_showUptime__13ThreadTestApp:
	addw #-12,sp
	movel d2,sp@-
	movel sp@(20),a0
	movel a0@(6),sp@-
	movel sp,d2
	addql #8,d2
	movel d2,a1
	jbsr _getUptime__C6Thread
	movel d2,sp@-
	jbsr _millisecs__C8Interval
	movel d0,sp@-
	movel d2,sp@-
	jbsr _secs__C8Interval
	movel d0,sp@
	movel d2,sp@-
	jbsr _mins__C8Interval
	movel d0,sp@
	movel d2,sp@-
	jbsr _hours__C8Interval
	movel d0,sp@
	movel d2,sp@-
	jbsr _days__C8Interval
	movel d0,sp@
	pea LC25
	jbsr _printf
	addw #32,sp
	movel sp@+,d2
	addw #12,sp
	rts
.globl ___vt_13ThreadTestApp
	.even
___vt_13ThreadTestApp:
	.long 0
	.long ___tf13ThreadTestApp
	.long __dfRTTI__11Application
	.long _run__13ThreadTestApp
	.long __$_13ThreadTestApp
	.skip 4
	.even
___thunk_96_notifyReturned__8MyThreadP6Threadl:
	movel sp@(12),sp@-
	movel sp@(12),sp@-
	moveq #-96,d0
	addl sp@(12),d0
	movel d0,sp@-
	jbsr _notifyReturned__8MyThreadP6Threadl
	addw #12,sp
	rts
	nop
	.even
___thunk_96_notifyThrown__8MyThreadP6ThreadPC12RuntimeError:
	movel sp@(12),sp@-
	movel sp@(12),sp@-
	moveq #-96,d0
	addl sp@(12),d0
	movel d0,sp@-
	jbsr _notifyThrown__8MyThreadP6ThreadPC12RuntimeError
	addw #12,sp
	rts
	nop
	.even
___thunk_96__$_8MyThread:
	movel sp@(8),sp@-
	moveq #-96,d0
	addl sp@(8),d0
	movel d0,sp@-
	jbsr __$_8MyThread
	addql #8,sp
	rts
	nop
.globl ___vt_8MyThread$17ThreadRunObserver
	.even
___vt_8MyThread$17ThreadRunObserver:
	.long -96
	.long ___tf8MyThread
	.long __dfRTTI__17ThreadRunObserver
	.long ___thunk_96_notifyReturned__8MyThreadP6Threadl
	.long ___thunk_96_notifyThrown__8MyThreadP6ThreadPC12RuntimeError
	.long ___thunk_96__$_8MyThread
	.skip 4
.globl ___vt_8MyThread
	.even
___vt_8MyThread:
	.long 0
	.long ___tf8MyThread
	.long __dfRTTI__6Thread
	.long _run__8MyThread
	.long __$_8MyThread
	.skip 4
.comm ___ti8MyThread,16
	.even
LC26:
	.long ___ti6Thread
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x1
	.long ___ti17ThreadRunObserver
	.byte 0x0
	.byte 0x0
	.byte 0x3
	.byte 0x1
LC27:
	.ascii "8MyThread\0"
.comm ___ti13ThreadTestApp,16
	.even
LC28:
	.long ___ti11Application
	.byte 0x0
	.byte 0x0
	.byte 0x0
	.byte 0x1
LC29:
	.ascii "13ThreadTestApp\0"
	.even
_days__C8Interval:
	movel sp@(4),sp@-
	jbsr _totDays__C8Interval
	movel d1,d0
	addql #4,sp
	rts
	nop
	.even
_millisecs__C8Interval:
	movel sp@(4),a0
	pea 1000:w
	clrl sp@-
	movel a0@(4),sp@-
	movel a0@,sp@-
	jbsr ___moddi3
	addw #16,sp
	movel d1,d0
	rts
	nop
	.even
_secs__C8Interval:
	movel sp@(4),sp@-
	jbsr _totSecs__C8Interval
	pea 60:w
	clrl sp@-
	movel d1,sp@-
	movel d0,sp@-
	jbsr ___moddi3
	addw #16,sp
	movel d1,d0
	addql #4,sp
	rts
	nop
	.even
_mins__C8Interval:
	movel sp@(4),sp@-
	jbsr _totMins__C8Interval
	pea 60:w
	clrl sp@-
	movel d1,sp@-
	movel d0,sp@-
	jbsr ___moddi3
	addw #16,sp
	movel d1,d0
	addql #4,sp
	rts
	nop
	.even
_hours__C8Interval:
	movel sp@(4),sp@-
	jbsr _totHours__C8Interval
	pea 24:w
	clrl sp@-
	movel d1,sp@-
	movel d0,sp@-
	jbsr ___moddi3
	addw #16,sp
	movel d1,d0
	addql #4,sp
	rts
	nop
	.even
___17ThreadRunObserver:
	movel sp@(4),a0
	movel #___vt_17ThreadRunObserver,a0@
	movel a0,d0
	rts
	nop
	.even
.globl ___tf8MyThread
___tf8MyThread:
	movel a2,sp@-
	lea ___ti8MyThread,a2
	tstl a2@
	jne L306
	jbsr ___tf17ThreadRunObserver
	jbsr ___tf6Thread
	pea 2:w
	pea LC26
	pea LC27
	movel a2,sp@-
	jbsr ___rtti_class
	addw #16,sp
L306:
	movel a2,d0
	movel sp@+,a2
	rts
	.even
.globl _setTrap__8MyThread
_setTrap__8MyThread:
	movel sp@(4),a0
	moveb #1,a0@(112)
	rts
	nop
	.even
.globl ___tf13ThreadTestApp
___tf13ThreadTestApp:
	movel a2,sp@-
	lea ___ti13ThreadTestApp,a2
	tstl a2@
	jne L309
	jbsr ___tf11Application
	pea 1:w
	pea LC28
	pea LC29
	movel a2,sp@-
	jbsr ___rtti_class
	addw #16,sp
L309:
	movel a2,d0
	movel sp@+,a2
	rts
	.even
_totSecs__C8Interval:
	movel sp@(4),a0
	pea 1000:w
	clrl sp@-
	movel a0@(4),sp@-
	movel a0@,sp@-
	jbsr ___divdi3
	addw #16,sp
	rts
	nop
	.even
_totMins__C8Interval:
	movel sp@(4),a0
	movel #60000,sp@-
	clrl sp@-
	movel a0@(4),sp@-
	movel a0@,sp@-
	jbsr ___divdi3
	addw #16,sp
	rts
	nop
	.even
_totHours__C8Interval:
	movel sp@(4),a0
	movel #3600000,sp@-
	clrl sp@-
	movel a0@(4),sp@-
	movel a0@,sp@-
	jbsr ___divdi3
	addw #16,sp
	rts
	nop
	.even
_totDays__C8Interval:
	movel sp@(4),a0
	movel #86400000,sp@-
	clrl sp@-
	movel a0@(4),sp@-
	movel a0@,sp@-
	jbsr ___divdi3
	addw #16,sp
	rts
	nop
