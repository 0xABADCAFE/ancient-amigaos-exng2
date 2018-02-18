///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         iolib/xsfio.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  XSF IO definitions
//  Comment(s):
//  Library:      IO
//  Created:      2007-04-19
//  Updated:      2007-04-19
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill, Serkan YAZICI
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _EXNG2_IOLIB_XSFIO_HPP_
#	define _EXNG2_IOLIB_XSFIO_HPP_

#	include <iolib/streamio.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Base definitions
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class XSF {
	public:
		class XSFError;
		class IncompatibleVersionError;
		class IncompatibleFormatError;
		class IncompatibleSubformatError;
		class BadStorableError;
		class UnreadyStorableError;

};

class XSF::XSFError										: public RuntimeError { DEFINE_MIN_RTTI };
class XSF::IncompatibleVersionError		: public XSF::XSFError { DEFINE_MIN_RTTI };
class XSF::IncompatibleFormatError		: public XSF::XSFError { DEFINE_MIN_RTTI };
class XSF::IncompatibleSubformatError	: public XSF::XSFError { DEFINE_MIN_RTTI };
class XSF::BadStorableError						: public XSF::XSFError { DEFINE_MIN_RTTI };
class XSF::UnreadyStorableError				: public XSF::XSFError { DEFINE_MIN_RTTI };


class XSFStream {
	DEFINE_MIN_RTTI
	protected:
		class XSFHeader : protected EXNGPrivate::StreamUser {
			private:
				// basic XSF data
				static char	xsfId[4];
				uint8				xsfVersion;
				uint8				xsfRevision;

				// payload data
				char				payloadId[6];
				uint8				payloadVersion;
				uint8				payloadRevision;

				// stream data
				uint8				machineFlags;
				uint8				accessorFlags;

				void	init();

			public:
				void	read(StreamIn* in);
				void	read(StreamOut* out);
				void	write(StreamOut* out);
				uint8	getXSFVersion()				const { return xsfVersion; }
				uint8	getXSFRevision()			const { return xsfRevision; }
				uint8	getPayloadVersion()		const { return payloadVersion; }
				uint8	getPayloadRevision()	const { return payloadRevision; }
				uint8	getMachineFlags()			const { return machineFlags; }
				uint8 getAccessorFlags()		const { return accessorFlags; }


		};

};

#endif
