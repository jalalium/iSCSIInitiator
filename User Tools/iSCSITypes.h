/*!
 * @author		Nareg Sinenian
 * @file		iSCSITypes.h
 * @version		1.0
 * @copyright	(c) 2013-2015 Nareg Sinenian. All rights reserved.
 * @brief		iSCSI data types used in user space.  All of the data types
 *              defined here are based on Core Foundation (CF) data types.
 */

#ifndef __ISCSI_TYPES_H__
#define __ISCSI_TYPES_H__

#include <CoreFoundation/CoreFoundation.h>
#include "iSCSITypesShared.h"

typedef CFMutableDictionaryRef iSCSIMutablePortalRef;
typedef CFDictionaryRef iSCSIPortalRef;

typedef CFDictionaryRef iSCSITargetRef;
typedef CFMutableDictionaryRef iSCSIMutableTargetRef;

typedef CFDictionaryRef iSCSIAuthRef;

typedef CFMutableDictionaryRef iSCSIMutableDiscoveryRecRef;

/*! Valid iSCSI authentication methods. */
enum iSCSIAuthMethods {
    
    /*! No authentication. */
    kiSCSIAuthMethodNone = 0,
    
    /*! CHAP authentication. */
    kiSCSIAuthMethodCHAP = 1, 
    
    /*! Invalid authentication method. */
    kiSCSIAuthMethodInvalid
};

/*! Detailed login response from a target. */
enum iSCSILoginStatusCode {
    kiSCSILoginSuccess = 0x0000,
    kiSCSILoginTargetMovedTemp = 0x0101,
    kiSCSILoginTargetMovedPerm = 0x0102,
    kiSCSILoginInitiatorError = 0x0200,
    kiSCSILoginAuthFail = 0x0201,
    kiSCSILoginAccessDenied = 0x0202,
    kiSCSILoginNotFound = 0x0203,
    kiSCSILoginTargetRemoved = 0x0204,
    kiSCSILoginUnsupportedVer = 0x0205,
    kiSCSILoginTooManyConnections = 0x0206,
    kiSCSILoginMissingParam = 0x0207,
    kiSCSILoginCantIncludeInSeession = 0x0208,
    kiSCSILoginSessionTypeUnsupported = 0x0209,
    kiSCSILoginSessionDoesntExist = 0x020a,
    kiSCSILoginInvalidReqDuringLogin = 0x020b,
    kiSCSILoginTargetHWorSWError = 0x0300,
    kiSCSILoginServiceUnavailable = 0x0301,
    kiSCSILoginOutOfResources = 0x0302,
    kiSCSILoginInvalidStatusCode
};

/*! Detailed logout response from a target. */
enum iSCSILogoutStatusCode {
    kiSCSILogoutSuccess = 0x0000,
    kiSCSILogoutCIDNotFound = 0x0001,
    kiSCSILogoutRecoveryNotSupported = 0x0002,
    kiSCSILogoutCleanupFailed = 0x0003,
    kiSCSILogoutInvalidStatusCode
};


/*! Creates a new portal object from byte representation.
 *  @param bytes data sued to construct a portal object.
 *  @return an iSCSI portal object or NULL if object creation failed. */
iSCSIPortalRef iSCSIPortalCreateFromBytes(CFDataRef bytes);

/*! Creates a new iSCSIPortal object with empty portal parameters.
 *  @return a new portal object. */
iSCSIMutablePortalRef iSCSIMutablePortalCreate();

/*! Gets the address associated with the iSCSI portal.
 *  @param an iSCSI portal object.
 *  @return the IP or DNS of the portal or NULL if the portal is invalid. */
CFStringRef iSCSIPortalGetAddress(iSCSIPortalRef portal);

/*! Sets the address associated with the iSCSI portal.  This function has
 *  no effect if the address is blank.
 *  @param portal an iSCSI portal object.
 *  @param address the address to associated with the specified portal. */
void iSCSIPortalSetAddress(iSCSIMutablePortalRef portal,CFStringRef address);

/*! Gets the port associated with the iSCSI portal.
 *  @param portal an iSCSI portal object.
 *  @return the port associated with the portal or NULL if the portal is invalid. */
CFStringRef iSCSIPortalGetPort(iSCSIPortalRef portal);

/*! Sets the port associated with the iSCSI portal.  This function has no 
 *  effect if the portal name is blank.
 *  @param portal an iSCSI portal object.
 *  @param port the port to associate with the specified portal. */
void iSCSIPortalSetPort(iSCSIMutablePortalRef portal,CFStringRef port);

/*! Gets the interface associated with the iSCSI portal.
 *  @param portal an iSCSI portal object.
 *  @return the host interface associated with the specified portal or NULL
 *  if the portal is invalid. */
CFStringRef iSCSIPortalGetHostInterface(iSCSIPortalRef portal);

/*! Sets the interface associated with the iSCSI portal.
 *  @param portal an iSCSI portal object.
 *  @param hostInterface the host interface to associate with the specified
 *  portal. */
void iSCSIPortalSetHostInterface(iSCSIMutablePortalRef portal,
                                 CFStringRef hostInterface);

/*! Releases memory associated with an iSCSI portal object.
 *  @param portal an iSCSI portal object. */
void iSCSIPortalRelease(iSCSITargetRef portal);

/*! Retains an iSCSI portal object.
 *  @param portal an iSCSI portal object. */
void iSCSIPortalRetain(iSCSITargetRef portal);

/*! Creates a new portal object from a dictionary representation.
 * @param dict a dictionary used to construct an iSCSI portal object.
 * @return an iSCSI portal object or NULL if object creation failed. */
iSCSIPortalRef iSCSIPortalCreateFromDictionary(CFDictionaryRef dict);

/*! Copies a target object to a dictionary representation.
 *  @param portal an iSCSI portal object.
 *  @return a dictionary representation of the portal or
 *  NULL if portal is invalid. */
CFDictionaryRef iSCSIPortalCopyToDictionary(iSCSIPortalRef portal);

/*! Copies the portal object to a byte array representation.
 *  @param portal an iSCSI poratl object.
 *  @return data representing the portal or NULL if the portal is invalid. */
CFDataRef iSCSIPortalCopyToBytes(iSCSIPortalRef portal);





/*! Creates a new target object from byte representation.
 * @param bytes data used to construct an iSCSI target object.
 * @return an iSCSI target object or NULL if object creation failed */
iSCSITargetRef iSCSITargetCreateFromBytes(CFDataRef bytes);

/*! Creates a new iSCSITarget object with empty target parameters.
 *  @return an iSCSI target object. */
iSCSIMutableTargetRef iSCSIMutableTargetCreate();

/*! Gets the name associated with the iSCSI target.
  * @param target the iSCSI target object.
 *  @return the target name or NULL if one was not set.  */
CFStringRef iSCSITargetGetName(iSCSITargetRef target);

/*! Sets the name associated with the iSCSI target.  This function has no
 *  effect if the specified target name is blank.
 *  @param target the target object.
 *  @param name the name to set. */
void iSCSITargetSetName(iSCSIMutableTargetRef target,CFStringRef name);

/*! Gets whether a header digest is enabled in the target object.
 *  @param target the iSCSI target object.
 *  @return true if header digest is enabled, false otherwise. */
bool iSCSITargetGetHeaderDigest(iSCSITargetRef target);

/*! Sets whether a header digest is enabled in the target object.
  * @param target the iSCSI target object. 
  * @param enable true to enable header digest. */
void iSCSITargetSetHeaderDigest(iSCSIMutableTargetRef target,bool enable);

/*! Gets whether a data digest is enabled in the target object.
 *  @param target the iSCSI target object.
 *  @return true if data digest is enabled, false otherwise. */
bool iSCSITargetGetDataDigest(iSCSITargetRef target);

/*! Sets whether a data digest is enabled in the target object.
  * @param target the iSCSI target object. 
  * @param enable true to enable data digest. */
void iSCSITargetSetDataDigest(iSCSIMutableTargetRef target,bool enable);

/*! Releases memory associated with an iSCSI target object.
 * @param target the iSCSI target object. */
void iSCSITargetRelease(iSCSITargetRef target);

/*! Retains an iSCSI target object.
  * @param target the iSCSI target object. */
void iSCSITargetRetain(iSCSITargetRef target);

/*! Creates a new target object from a dictionary representation.
 * @param dict a dictionary used to construct an iSCSI target object.
 * @return an iSCSI target object or NULL if object creation failed. */
iSCSITargetRef iSCSITargetCreateFromDictionary(CFDictionaryRef dict);

/*! Copies a target object to a dictionary representation.
 *  @param target an iSCSI target object.
 *  @return a dictionary representation of the target or 
 *  NULL if target is invalid. */
CFDictionaryRef iSCSITargetCopyToDictionary(iSCSITargetRef target);

/*! Copies the target object to a byte array representation.
 *  @param target an iSCSI target object.
 *  @return data representing the target or NULL if the target is invalid. */
CFDataRef iSCSITargetCopyToBytes(iSCSITargetRef target);




/*! Creates a new authentication object from byte representation.
 * @param bytes data used to construct an iSCSI authentication object.
 * @return an iSCSI authentication object or NULL if object creation failed */
iSCSIAuthRef iSCSIAuthCreateFromBytes(CFDataRef bytes);

/*! Creates a new iSCSIAuth object with empty authentication parameters
 *  (defaults to no authentication).
 *  @return a new iSCSI authentication object. */
iSCSIAuthRef iSCSIAuthCreateNone();

/*! Creates a new iSCSIAuth object for CHAP authentication.  The initiatorUser
 *  and initiatorSecret are both required parameters, while targetUser and 
 *  targetSecret are optional.  This function will fail to return an 
 *  authentication object if the first two parameters are not specified.
 *  @param initiatorUser the user name for CHAP.
 *  @param initiatorSecret the shared CHAP secret.
 *  @param targetUser the user name for mutual CHAP (may be NULL if mutual
 *  CHAP is not used).
 *  @param targetSecret the shared secret for mutual CHAP (may be NULL if 
 *  mutual CHAP is not used). 
 *  @return an iSCSI authentication object, or NULL if the parameters were
 *  invalid. */
iSCSIAuthRef iSCSIAuthCreateCHAP(CFStringRef initiatorUser,
                                 CFStringRef initiatorSecret,
                                 CFStringRef targetUser,
                                 CFStringRef targetSecret);

/*! Returns the CHAP authentication parameter values if the authentication
 *  method is actually CHAP.
 *  @param auth an iSCSI authentication object.
 *  @param initiatorUser the user name for CHAP.
 *  @param initiatorSecret the shared CHAP secret.
 *  @param targetUser the user name for mutual CHAP (may be NULL if mutual
 *  CHAP is not used).
 *  @param targetSecret the shared secret for mutual CHAP (may be NULL if
 *  mutual CHAP is not used). */
void iSCSIAuthGetCHAPValues(iSCSIAuthRef auth,
                            CFStringRef * initiatorUser,
                            CFStringRef * initiatorSecret,
                            CFStringRef * targetUser,
                            CFStringRef * targetSecret);


/*! Gets the authentication method used.
 *  @param auth an iSCSI authentication object.
 *  @return the authentication method used. */
enum iSCSIAuthMethods iSCSIAuthGetMethod(iSCSIAuthRef auth);

/*! Releases memory associated with an iSCSI auth object.
 *  @param auth an iSCSI authentication object. */
void iSCSIAuthRelease(iSCSIAuthRef auth);

/*! Retains an iSCSI auth object.
 *  @param auth an iSCSI authentication object. */
void iSCSIAuthRetain(iSCSIAuthRef auth);

/*! Creates a new authentication object from a dictionary representation.
 * @return an iSCSI authentication object or NULL if object creation failed. */
iSCSIAuthRef iSCSIAuthCreateFromDictionary(CFDictionaryRef dict);

/*! Copies an authentication object to a dictionary representation.
 *  @param auth an iSCSI authentication object.
 *  @return a dictionary representation of the authentication object or
 *  NULL if authentication object is invalid. */
CFDictionaryRef iSCSIAuthCopyToDictionary(iSCSIAuthRef auth);

/*! Copies the authentication object to a byte array representation.
 *  @param auth an iSCSI authentication object.
 *  @return data representing the authentication object 
 *  or NULL if the authenticaiton object is invalid. */
CFDataRef iSCSIAuthCopyToBytes(iSCSIAuthRef auth);





/*! Creates a discovery record from data obtained from a send targets operation. */
iSCSIMutableDiscoveryRecRef iSCSIMutableDiscoveryRecCreate();

/*! Add a portal to a specified portal group tag for a given target.
 *  @param discoveryRec the discovery record.
 *  @param targetName the name of the target to add.
 *  @param portalGroupTag the target portal group tag to add.
 *  @param portal the iSCSI portal to add. */
void iSCSIDiscoveryRecAddPortal(iSCSIMutableDiscoveryRecRef discoveryRec,
                                CFStringRef targetName,
                                CFStringRef portalGroupTag,
                                iSCSIPortalRef portal);

/*! Creates a CFArray object containing CFString objects with names of
 *  all of the targets in the discovery record.
 *  @param discoveryRec the discovery record.
 *  @return an array of strings with names of the targets in the record. */
CFArrayRef iSCSIDiscoveryRecCreateArrayOfTargets(iSCSIMutableDiscoveryRecRef discoveryRec);


/*! Creates a CFArray object containing CFString objects with portal group
 *  tags for a particular target.
 *  @param discoveryRec the discovery record.
 *  @param targetName the name of the target.
 *  @return an array of strings with portal group tags for the specified target. */
CFArrayRef iSCSIDiscoveryRecCreateArrayOfPortalGroupTags(iSCSIMutableDiscoveryRecRef discoveryRec,
                                                         CFStringRef targetName);


/*! Gets all of the portals associated with a partiular target and portal
 *  group tag.  
 *  @param discoveryRec the discovery record.
 *  @param targetName the name of the target.
 *  @param portalGroupTag the portal group tag associated with the target.
 *  @return an array of iSCSIPortal objects associated with the specified
 *  group tag for the specified target. */
CFArrayRef iSCSIDiscoveryRecGetPortals(iSCSIMutableDiscoveryRecRef discoveryRec,
                                       CFStringRef targetName,
                                       CFStringRef portalGroupTag);


/*! Releases memory associated with an iSCSI discovery record object.
 * @param target the iSCSI discovery record object. */
void iSCSIDiscoveryRecRelease(iSCSIMutableDiscoveryRecRef discoveryRec);

/*! Retains an iSCSI discovery record object.
 * @param target the iSCSI discovery record object. */
void iSCSIDiscoveryRecRetain(iSCSIMutableDiscoveryRecRef discoveryRec);

/*! Copies an iSCSI discovery record object to a dictionary representation.
 *  @param auth an iSCSI discovery record object.
 *  @return a dictionary representation of the discovery record object or
 *  NULL if the discovery record object is invalid. */
CFDictionaryRef iSCSIDiscoveryRecCopyToDictionary(iSCSIMutableDiscoveryRecRef discoveryRec);

/*! Copies the discovery record object to a byte array representation.
 *  @param auth an iSCSI discovery record object.
 *  @return data representing the discovery record object
 *  or NULL if the discovery record object is invalid. */
CFDataRef iSCSIDiscoveryRecCopyToBytes(iSCSIMutableDiscoveryRecRef discoveryRec);



#endif
