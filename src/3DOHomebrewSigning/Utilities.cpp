#include <stdio.h>

#include "bigd.h"
#include "md5.h"

void CalculateMD5(unsigned char *_pBuffer, int _iDataSize, unsigned char *_pMD5)
{
  // MD5 context
  MD5_CTX	sMD5Context;
		
  MD5Init(&sMD5Context);
	
  MD5Update(&sMD5Context, _pBuffer, _iDataSize);
  
  MD5Final(_pMD5, &sMD5Context);
}

void CalculateRSA(unsigned char *pMessage, unsigned char *_pRSA, bool _bUseKey2)
{
  BIGD	n1	= bdNew();
  BIGD	d1	= bdNew();
  BIGD	m	= bdNew();
  BIGD	s	= bdNew();

  if (false == _bUseKey2)
    {
      bdConvFromDecimal(n1, "9848629834960601161765696679721159386472195710802975774894097161799508454663972383623145204190992555825654001836919677277509412015512909914412280235809649");
      bdConvFromDecimal(d1, "1293424431840119233399718499814761414763663098446392305026374327045918630228589915421353480949734793978038214646649008563728161865424388240308738298816913");
    }

  else
    {
      bdConvFromDecimal(n1, "9300599932705551463599466527377771225341583519175853550791859282008578500399528445758115451929935900334192412333960106705831250250018072975160929028951191");
      bdConvFromDecimal(d1, "3507397765183296525975568232054284081271911083455623853820296964384119163790981747009862925376317583489353369459236855907689701499704961726960510915919713");
    }

  char	szCombined[128];

  // Combine the MD5 with the 'extra' string.
  sprintf(szCombined, "%s%s", "1ffffffffffffffffffffffffffffffffffffffffffffffffffffff003020300c06082a864886f70d020505000410", pMessage);
	
  bdConvFromHex(m, szCombined);

  // Calculate RSA
  bdModExp(s, m, d1, n1);

  // Convert into an unsigned byte array
  bdConvToOctets(s, (unsigned char*)_pRSA, 64);
}
