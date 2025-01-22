#pragma once

// Calculate MD5 checksum
void CalculateMD5(char *_pBuffer, int _iDataSize, char *_pMD5);

// Calculate RSA
void CalculateRSA(char *pMessage, char *_pRSA, bool _bUseKey2 = false);
