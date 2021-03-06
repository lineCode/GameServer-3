#ifndef CMarketEvent_H_
#define CMarketEvent_H_

#include "CGameMesEvent.h"
#include "CMD_Game.h"
#include "CGlobeData.h"

class CCMarketEvent:public CCGameMesEvent
{
private:


public:
	CCMarketEvent(CCGameMesManager *pMesManager,CT_WORD id);
	~CCMarketEvent();
private:
	//处理用户消息
	virtual CT_VOID OnUserEvent(CT_DWORD mainID,CT_DWORD subID,CT_CHAR* pBuf,CT_DWORD len,CT_LONGLONG reserve);
	//用户定时器处理
	virtual CT_VOID OnTime(CT_DWORD timeID);
	//用户时钟处理
	virtual CT_VOID OnClock(CT_DWORD timeID);
private:
	CT_VOID DisposeShopping(CT_CHAR* pBuf,CT_DWORD len);
	CT_VOID	DisposeRefresh(CT_CHAR* pBuf,CT_DWORD len);
	CT_BOOL DisposeNormalMarketShopping(CCUser *pUser,CMD_G_MarketShoppingInfo *pGoodsInfo);
	CT_BOOL DisposeMallMarketShopping(CCUser *pUser,CMD_G_MarketShoppingInfo *pGoodsInfo);
	CT_BOOL DisposeBlackMarketShopping(CCUser *pUser,CMD_G_MarketShoppingInfo *pGoodsInfo);
	CT_BOOL DisposeSeekBlackMarketShopping(CCUser *pUser,CMD_G_MarketShoppingInfo *pGoodsInfo);
	CT_BOOL DisposeMarketPersonal(CCUser *pUser,CMD_G_MarketShoppingInfo *pGoodsInfo);
	//购买体力
	CT_VOID DisposeBuyStatmina(CT_CHAR* pBuf,CT_DWORD len);
};

#endif