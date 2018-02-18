#NO_APP
.text
LC0:
	.ascii "Unhandled %s in startup: argument '%s' %s\12\0"
LC1:
	.ascii "Unhandled %s in startup: resource '%s' %s\12\0"
LC2:
	.ascii "Unhandled %s in startup\12\0"
LC3:
	.ascii "Unhandled %s in cleanup\12\0"
.data
	.even
_errorString.87:
	.long LC0
	.long LC1
	.long LC2
	.long LC3
.text
LC4:
	.ascii "eXtropia C++ framework compiled with EXNG2_BUILD_LOGGED option\12\0"
LC5:
	.ascii "Startup complete, creating application instance\12\0"
LC6:
	.ascii "Application instance created, invoking run()\12\0"
LC7:
	.ascii "is required\0"
LC8:
	.ascii "is invalid\0"
LC9:
	.ascii " is unavailable\0"
LC10:
	.ascii " encountered a problem\0"
LC11:
	.ascii "exception\0"
LC12:
	.ascii "Destroying application\12\0"
	.even
.globl _main
_main:
	link a5,#-476
	fmovem #0xfc,sp@-
	moveml #0x3f3a,sp@-
	jbsr ___get_eh_context
	movel d0,d1
	clrl a5@(-436)
	clrl a5@(-440)
	movel d1,a0
	addql #4,a0
	movel a0@,a5@(-24)
	clrl a5@(-20)
	movel a5,a5@(-16)
	movel #L107,a5@(-12)
	movel sp,a5@(-8)
	jra L106
	.even
L107:
	jra L198
	.even
L106:
	lea a5@(-24),a1
	movel a1,a0@
	movel a5@(12),sp@-
	movel a5@(8),sp@-
	movel d1,a0
	addql #4,a0
	movel a0,a5@(-476)
	jbsr _init__7StartupiPPc
	pea LC4
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	pea LC5
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	jbsr _createInstance__11Application
	movel d0,a5@(-436)
	pea LC6
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	addw #32,sp
	movel a5@(-436),a1
	movel a1@,a0
	movel a1,sp@-
	movel a0@(12),a0
	jbsr a0@
	movel d0,a5@(-440)
	movel a5@(-476),a1
	movel a1@,a0
	movel a0@,a1@
L201:
	addql #4,sp
	movel a5@(-476),a0
	movel a0@,a5@(-192)
	clrl a5@(-188)
	lea a5@(-184),a0
	movel a5,a0@
	movel #L152,a0@(4)
	movel sp,a0@(8)
	jra L151
	.even
L152:
	jra L199
	.even
L151:
	lea a5@(-192),a0
	movel a5@(-476),a1
	movel a0,a1@
	pea LC12
	pea 3:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	movel a5@(-436),sp@-
	jbsr _destroyInstance__11ApplicationP11Application
	movel a5@(-476),a1
	movel a1@,a0
	movel a0@,a1@
	addw #12,sp
L153:
	jbsr _done__7Startup
	movel a5@(-440),d0
	jra L197
	.even
L198:
L104:
	pea ___tfQ211Application15MissingArgument
	jbsr ___eh_rtime_match
	addql #4,sp
	tstl d0
	jeq L115
	jbsr ___start_cp_handler
	movel d0,a5@(-444)
	movel a5@(-476),a0
	movel a0@,a5@(-48)
	clrl a5@(-44)
	movel a5,a5@(-40)
	movel #L113,a5@(-36)
	movel sp,a5@(-32)
	jra L112
	.even
L113:
	jra L200
	.even
L112:
	lea a5@(-48),a0
	movel a5@(-476),a1
	movel a0,a1@
	movel a5@(-444),a1
	movel a1@(8),a0
	pea LC7
	movel a0@(4),sp@-
	movel a0@,a1
	movel a0,sp@-
	movel a1@(12),a0
	jbsr a0@
	movel d0,sp@
	movel _errorString.87,sp@-
	pea 1:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	movel a5@(-476),a1
	movel a1@,a0
	movel a0@,a1@
	addw #16,sp
	movel a5@(-444),sp@
	jbsr ___cp_pop_exception
	jra L201
	.even
L115:
	pea ___tfQ211Application15InvalidArgument
	jbsr ___eh_rtime_match
	addql #4,sp
	tstl d0
	jeq L122
	jbsr ___start_cp_handler
	movel d0,a5@(-448)
	movel a5@(-476),a0
	movel a0@,a5@(-72)
	clrl a5@(-68)
	movel a5,a5@(-64)
	movel #L120,a5@(-60)
	movel sp,a5@(-56)
	jra L119
	.even
L120:
	jra L202
	.even
L119:
	lea a5@(-72),a0
	movel a5@(-476),a1
	movel a0,a1@
	movel a5@(-448),a1
	movel a1@(8),a0
	pea LC8
	movel a0@(4),sp@-
	movel a0@,a1
	movel a0,sp@-
	movel a1@(12),a0
	jbsr a0@
	movel d0,sp@
	movel _errorString.87,sp@-
	pea 1:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	movel a5@(-476),a1
	movel a1@,a0
	movel a0@,a1@
	addw #16,sp
	movel a5@(-448),sp@
	jbsr ___cp_pop_exception
	jra L201
	.even
L122:
	pea ___tf19ResourceUnavailable
	jbsr ___eh_rtime_match
	addql #4,sp
	tstl d0
	jeq L130
	jbsr ___start_cp_handler
	movel d0,a5@(-452)
	movel a5@(-476),a0
	movel a0@,a5@(-96)
	clrl a5@(-92)
	movel a5,a5@(-88)
	movel #L127,a5@(-84)
	movel sp,a5@(-80)
	jra L126
	.even
L127:
	jra L203
	.even
L126:
	lea a5@(-96),a0
	movel a5@(-476),a1
	movel a0,a1@
	movel a5@(-452),a1
	movel a1@(8),a0
	pea LC9
	movel a0@(4),sp@-
	movel a0@,a1
	movel a0,sp@-
	movel a1@(12),a0
	jbsr a0@
	movel d0,sp@
	movel _errorString.87+4,sp@-
	pea 1:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	movel a5@(-476),a1
	movel a1@,a0
	movel a0@,a1@
	addw #16,sp
	movel a5@(-452),sp@
	jbsr ___cp_pop_exception
	jra L201
	.even
L130:
	pea ___tf13ResourceError
	jbsr ___eh_rtime_match
	addql #4,sp
	tstl d0
	jeq L138
	jbsr ___start_cp_handler
	movel d0,a5@(-456)
	movel a5@(-476),a0
	movel a0@,a5@(-120)
	clrl a5@(-116)
	movel a5,a5@(-112)
	movel #L135,a5@(-108)
	movel sp,a5@(-104)
	jra L134
	.even
L135:
	jra L204
	.even
L134:
	lea a5@(-120),a0
	movel a5@(-476),a1
	movel a0,a1@
	movel a5@(-456),a1
	movel a1@(8),a0
	pea LC10
	movel a0@(4),sp@-
	movel a0@,a1
	movel a0,sp@-
	movel a1@(12),a0
	jbsr a0@
	movel d0,sp@
	movel _errorString.87+4,sp@-
	pea 1:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	movel a5@(-476),a1
	movel a1@,a0
	movel a0@,a1@
	addw #16,sp
	movel a5@(-456),sp@
	jbsr ___cp_pop_exception
	jra L201
	.even
L138:
	pea ___tf12RuntimeError
	jbsr ___eh_rtime_match
	addql #4,sp
	tstl d0
	jeq L144
	jbsr ___start_cp_handler
	movel d0,a5@(-460)
	movel a5@(-476),a0
	movel a0@,a5@(-144)
	clrl a5@(-140)
	lea a5@(-136),a0
	movel a5,a0@
	movel #L143,a0@(4)
	movel sp,a5@(-128)
	jra L142
	.even
L143:
	jra L205
	.even
L142:
	lea a5@(-144),a0
	movel a5@(-476),a1
	movel a0,a1@
	movel a5@(-460),a1
	movel a1@(8),a0
	movel a0@,a1
	movel a0,sp@-
	movel a1@(12),a0
	jbsr a0@
	movel d0,sp@-
	movel _errorString.87+8,sp@-
	pea 1:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	movel a5@(-476),a1
	movel a1@,a0
	movel a0@,a1@
	addw #12,sp
	movel a5@(-460),sp@
	jbsr ___cp_pop_exception
	jra L201
	.even
L144:
	jbsr ___start_cp_handler
	movel d0,a5@(-464)
	movel a5@(-476),a0
	movel a0@,a5@(-168)
	clrl a5@(-164)
	lea a5@(-160),a0
	movel a5,a0@
	movel #L148,a0@(4)
	movel sp,a0@(8)
	jra L147
	.even
L148:
	jra L206
	.even
L147:
	lea a5@(-168),a0
	movel a5@(-476),a1
	movel a0,a1@
	pea LC11
	movel _errorString.87+8,sp@-
	pea 1:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	movel a5@(-476),a1
	movel a1@,a0
	movel a0@,a1@
	addqw #8,sp
	movel a5@(-464),sp@
	jbsr ___cp_pop_exception
	jra L201
	.even
L200:
L110:
	movel a5@(-476),a0
	movel a0@,a5@(-216)
	clrl a5@(-212)
	lea a5@(-208),a0
	movel a5,a0@
	movel #L157,a0@(4)
	movel sp,a0@(8)
	jra L156
	.even
L157:
	jra L207
	.even
L156:
	lea a5@(-216),a0
	movel a5@(-476),a1
	movel a0,a1@
	movel a5@(-444),sp@-
	jbsr ___cp_pop_exception
	movel a5@(-476),a1
	movel a1@,a0
	movel a0@,a1@
	addql #4,sp
	jbsr ___sjthrow
	.even
L202:
L117:
	movel a5@(-476),a0
	movel a0@,a5@(-240)
	clrl a5@(-236)
	lea a5@(-232),a0
	movel a5,a0@
	movel #L161,a0@(4)
	movel sp,a0@(8)
	jra L160
	.even
L161:
	jra L208
	.even
L160:
	lea a5@(-240),a0
	movel a5@(-476),a1
	movel a0,a1@
	movel a5@(-448),sp@-
	jbsr ___cp_pop_exception
	movel a5@(-476),a1
	movel a1@,a0
	movel a0@,a1@
	addql #4,sp
	jbsr ___sjthrow
	.even
L203:
L124:
	movel a5@(-476),a0
	movel a0@,a5@(-264)
	clrl a5@(-260)
	lea a5@(-256),a0
	movel a5,a0@
	movel #L165,a0@(4)
	movel sp,a0@(8)
	jra L164
	.even
L165:
	jra L209
	.even
L164:
	lea a5@(-264),a0
	movel a5@(-476),a1
	movel a0,a1@
	movel a5@(-452),sp@-
	jbsr ___cp_pop_exception
	movel a5@(-476),a1
	movel a1@,a0
	movel a0@,a1@
	addql #4,sp
	jbsr ___sjthrow
	.even
L204:
L132:
	movel a5@(-476),a0
	movel a0@,a5@(-288)
	clrl a5@(-284)
	lea a5@(-280),a0
	movel a5,a0@
	movel #L169,a0@(4)
	movel sp,a0@(8)
	jra L168
	.even
L169:
	jra L210
	.even
L168:
	lea a5@(-288),a0
	movel a5@(-476),a1
	movel a0,a1@
	movel a5@(-456),sp@-
	jbsr ___cp_pop_exception
	movel a5@(-476),a1
	movel a1@,a0
	movel a0@,a1@
	addql #4,sp
	jbsr ___sjthrow
	.even
L205:
L140:
	movel a5@(-476),a0
	movel a0@,a5@(-312)
	clrl a5@(-308)
	lea a5@(-304),a0
	movel a5,a0@
	movel #L173,a0@(4)
	movel sp,a0@(8)
	jra L172
	.even
L173:
	jra L211
	.even
L172:
	lea a5@(-312),a0
	movel a5@(-476),a1
	movel a0,a1@
	movel a5@(-460),sp@-
	jbsr ___cp_pop_exception
	movel a5@(-476),a1
	movel a1@,a0
	movel a0@,a1@
	addql #4,sp
	jbsr ___sjthrow
	.even
L206:
L145:
	movel a5@(-476),a0
	movel a0@,a5@(-336)
	clrl a5@(-332)
	lea a5@(-328),a0
	movel a5,a0@
	movel #L177,a0@(4)
	movel sp,a0@(8)
	jra L176
	.even
L177:
	jra L212
	.even
L176:
	lea a5@(-336),a0
	movel a5@(-476),a1
	movel a0,a1@
	movel a5@(-464),sp@-
	jbsr ___cp_pop_exception
	movel a5@(-476),a1
	movel a1@,a0
	movel a0@,a1@
	addql #4,sp
	jbsr ___sjthrow
	.even
L199:
L149:
	pea ___tf12RuntimeError
	jbsr ___eh_rtime_match
	addql #4,sp
	tstl d0
	jeq L183
	jbsr ___start_cp_handler
	movel d0,a5@(-468)
	movel a5@(-476),a0
	movel a0@,a5@(-360)
	clrl a5@(-356)
	lea a5@(-352),a0
	movel a5,a0@
	movel #L182,a0@(4)
	movel sp,a0@(8)
	jra L181
	.even
L182:
	jra L213
	.even
L181:
	lea a5@(-360),a0
	movel a5@(-476),a1
	movel a0,a1@
	movel a5@(-468),a1
	movel a1@(8),a0
	movel a0@,a1
	movel a0,sp@-
	movel a1@(12),a0
	jbsr a0@
	movel d0,sp@-
	movel _errorString.87+12,sp@-
	pea 1:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	movel a5@(-476),a1
	movel a1@,a0
	movel a0@,a1@
	addw #12,sp
	movel a5@(-468),sp@
	jra L214
	.even
L183:
	jbsr ___start_cp_handler
	movel d0,a5@(-472)
	movel a5@(-476),a0
	movel a0@,a5@(-384)
	clrl a5@(-380)
	lea a5@(-376),a0
	movel a5,a0@
	movel #L187,a0@(4)
	movel sp,a0@(8)
	jra L186
	.even
L187:
	jra L215
	.even
L186:
	lea a5@(-384),a0
	movel a5@(-476),a1
	movel a0,a1@
	pea LC11
	movel _errorString.87+12,sp@-
	pea 1:w
	jbsr _write__9SystemLogQ29SystemLog5LevelPCce
	movel a5@(-476),a1
	movel a1@,a0
	movel a0@,a1@
	addqw #8,sp
	movel a5@(-472),sp@
L214:
	jbsr ___cp_pop_exception
	addql #4,sp
	jra L153
	.even
L207:
L154:
	jbsr ___terminate
	.even
L208:
L158:
	jbsr ___terminate
	.even
L209:
L162:
	jbsr ___terminate
	.even
L210:
L166:
	jbsr ___terminate
	.even
L211:
L170:
	jbsr ___terminate
	.even
L212:
L174:
	jbsr ___terminate
	.even
L213:
L179:
	movel a5@(-476),a0
	movel a0@,a5@(-408)
	clrl a5@(-404)
	lea a5@(-400),a0
	movel a5,a0@
	movel #L191,a0@(4)
	movel sp,a0@(8)
	jra L190
	.even
L191:
	jra L216
	.even
L190:
	lea a5@(-408),a0
	movel a5@(-476),a1
	movel a0,a1@
	movel a5@(-468),sp@-
	jbsr ___cp_pop_exception
	movel a5@(-476),a1
	movel a1@,a0
	movel a0@,a1@
	addql #4,sp
	jbsr ___sjthrow
	.even
L215:
L184:
	movel a5@(-476),a0
	movel a0@,a5@(-432)
	clrl a5@(-428)
	lea a5@(-424),a0
	movel a5,a0@
	movel #L195,a0@(4)
	movel sp,a0@(8)
	jra L194
	.even
L195:
	jra L217
	.even
L194:
	lea a5@(-432),a0
	movel a5@(-476),a1
	movel a0,a1@
	movel a5@(-472),sp@-
	jbsr ___cp_pop_exception
	movel a5@(-476),a1
	movel a1@,a0
	movel a0@,a1@
	addql #4,sp
	jbsr ___sjthrow
	.even
L216:
L188:
	jbsr ___terminate
	.even
L217:
L192:
	jbsr ___terminate
	.even
L197:
	moveml a5@(-588),#0x5cfc
	fmovem a5@(-548),#0x3f
	unlk a5
	rts
