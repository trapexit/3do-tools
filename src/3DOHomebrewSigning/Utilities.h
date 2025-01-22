#pragma once

// Calculate MD5 checksum
void CalculateMD5(u8 *_pBuffer, int _iDataSize, u8 *_pMD5);

// Calculate RSA
void CalculateRSA(u8 *pMessage, u8 *_pRSA, bool _bUseKey2 = false);
