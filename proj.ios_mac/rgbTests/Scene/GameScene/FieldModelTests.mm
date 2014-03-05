//
//  FieldModelTests.m
//  rgb
//
//  Created by ntotani on 2014/03/05.
//
//

#import <XCTest/XCTest.h>
#import "FieldModel.h"
#import "FieldListenerMock.h"

@interface FieldModelTests : XCTestCase

@end

@implementation FieldModelTests

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

- (void)testBallCreate
{
    FieldModel* field = new FieldModel();
    FieldListenerMock* listener = new FieldListenerMock();
    field->addListener(listener);
    field->update(1);
    XCTAssertEqual(0, (int)field->getBalls().size());
    XCTAssertFalse(listener->called);
    XCTAssertFalse(listener->createdBall);
    field->update(2);
    XCTAssertEqual(1, (int)field->getBalls().size());
    XCTAssertTrue(listener->called);
    XCTAssertTrue(listener->createdBall);
}

@end
