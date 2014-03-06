//
//  BallModelTests.m
//  rgb
//
//  Created by ntotani on 2014/03/04.
//
//

#import <XCTest/XCTest.h>
#import "BallModel.h"
#import "BallListenerMock.h"

@interface BallModelTests : XCTestCase

@end

@implementation BallModelTests

- (void)setUp
{
    [super setUp];
    // Put setup code here; it will be run once, before the first test case.
}

- (void)tearDown
{
    // Put teardown code here; it will be run once, after the last test case.
    [super tearDown];
}

- (void)testGetX
{
    BallModel* ball = new BallModel(BallColor::RED, 0, 0, 32, 32, 0, 0);
    XCTAssertEqual(0.0f, ball->getX());
}

- (void)testMove
{
    BallModel* ball = new BallModel(BallColor::RED, 0, 0, 32, 32, 0, 10);
    BallListenerMock* listener = new BallListenerMock();
    ball->addListener(listener);
    ball->update(1);
    XCTAssertEqual(10.0f, ball->getY());
    XCTAssertTrue(listener->called);
    XCTAssertEqual(10.0f, listener->lastY);
}

@end
