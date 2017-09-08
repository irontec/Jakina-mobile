#ifndef __CCSCROLLLAYER__
#define __CCSCROLLLAYER__

//  CCScrollLayer.h
//
//  Copyright 2010 DK101
//  http://dk101.net/2010/11/30/implementing-page-scrolling-in-cocos2d/
//
//  Copyright 2010 Giv Parvaneh.
//  http://www.givp.org/blog/2010/12/30/scrolling-menus-in-cocos2d/
//
//  Copyright 2011 Stepan Generalov
//
//  Copyright 2011 Eli Yukelzon
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

// Original source: https://github.com/cocos2d/cocos2d-iphone-extensions/tree/master/Extensions/CCScrollLayer
// Last updated: October 1, 2011


#include <cocos2d.h>

namespace cocos2d {
    
	class CCScrollLayer;
    
	class CCScrollLayerDelegate
	{
        /*
	public:

		virtual void scrollLayerScrollingStarted(CCScrollLayer* sender) {}
        

		virtual void scrollLayerScrolledToPageNumber(CCScrollLayer* sender, unsigned int page) {}
         */
	};
    

	class CCScrollLayer : 	public Layer
	{
	public:
		CCScrollLayer();
		~CCScrollLayer();
        /*
		static CCScrollLayer* nodeWithLayers(CCArray* layers, int widthOffset);
		
		bool initWithLayers(CCArray* layers, int widthOffset);
        

		void updatePages();
        

		void addPage(CCLayer* aPage, unsigned int pageNumber);
        
		void addPage(CCLayer* aPage);
        

		void removePage(CCLayer* aPage);
        
		void removePageWithNumber(unsigned int pageNumber);
        

		void moveToPage(unsigned int pageNumber);
        

		void selectPage(unsigned int pageNumber);
        
		CC_SYNTHESIZE(CCScrollLayerDelegate*, m_pDelegate, Delegate);
        

		CC_SYNTHESIZE(float, m_fMinimumTouchLengthToSlide, MinimumTouchLengthToSlide);
        

		CC_SYNTHESIZE(float, m_fMinimumTouchLengthToChangePage, MinimumTouchLengthToChangePage);
        

		CC_SYNTHESIZE(bool, m_bStealTouches, StealTouches);
        

		CC_SYNTHESIZE(bool, m_bShowPagesIndicator, ShowPagesIndicator);
        

		CC_SYNTHESIZE_PASS_BY_REF(CCPoint, m_tPagesIndicatorPosition, PagesIndicatorPosition);
        
		unsigned int getTotalScreens() const;
        
		CC_SYNTHESIZE_READONLY(unsigned int, m_uCurrentScreen, CurrentScreen);
        
		CC_SYNTHESIZE(float, m_fPagesWidthOffset, PagesWidthOffset);
		
		CC_SYNTHESIZE(float, m_fMarginOffset, MarginOffset);
        
		CC_SYNTHESIZE_READONLY(CCArray*, m_pLayers, Pages);
	protected:
		// The x coord of initial point the user starts their swipe.
		float m_fStartSwipe;
        
		// Internal state of scrollLayer (scrolling or idle).
		int m_iState;
		bool m_bStealingTouchInProgress;
		// Holds the touch that started the scroll
		CCTouch* m_pScrollTouch;
        
		void visit();
		void moveToPageEnded();
		unsigned int pageNumberForPosition(const CCPoint& position);
		CCPoint positionForPageWithNumber(unsigned int pageNumber);
		void claimTouch(CCTouch* pTouch);
		void cancelAndStoleTouch(CCTouch* pTouch, CCEvent* pEvent);
        
		void registerWithTouchDispatcher();
		bool ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent);
		void ccTouchMoved(CCTouch* pTouch, CCEvent* pEvent);
		void ccTouchEnded(CCTouch* pTouch, CCEvent* pEvent);
		void ccTouchCancelled(CCTouch* pTouch, CCEvent* pEvent);
         */
	};
}

#endif
