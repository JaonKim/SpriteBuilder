//
//  CCBReader.h
//  ccBuilder
//
//  Created by Viktor Lidholt on 4/5/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "cocos2d.h"

enum {
    kCCBMemberVarAssignmentTypeNone = 0,
    kCCBMemberVarAssignmentTypeDocumentRoot = 1,
    kCCBMemberVarAssignmentTypeOwner = 2,
};

// CCBReader
@interface CCBReader : NSObject {
@private
    
}
+ (CCScene*) sceneWithNodeGraphFromFile:(NSString*) file;
+ (CCScene*) sceneWithNodeGraphFromFile:(NSString *)file owner:(id)owner;

+ (CCNode*) nodeGraphFromFile:(NSString*) file;
+ (CCNode*) nodeGraphFromFile:(NSString*) file owner:(id)owner;

+ (CCNode*) nodeGraphFromDictionary:(NSDictionary*) dict;
+ (CCNode*) nodeGraphFromDictionary:(NSDictionary*) dict owner:(NSObject*) owner;


+ (CCNode*) nodeGraphFromDictionary:(NSDictionary*) dict extraProps: (NSMutableDictionary*) extraProps assetsDir:(NSString*)path owner:(NSObject*)owner;
+ (CCNode*) ccObjectFromDictionary: (NSDictionary *)dict extraProps: (NSMutableDictionary*) extraProps assetsDir:(NSString*)path owner:(NSObject*)owner;
@end

// CCBTemplate
@interface CCBTemplate : NSObject
{
    NSString* fileName;
    NSString* propertyFile;
    NSString* customClass;
    NSString* previewImage;
    CGPoint previewAnchorpoint;
    id properties;
}

@property (nonatomic, retain) NSString* fileName;
@property (nonatomic, retain) NSString* propertyFile;
@property (nonatomic, retain) NSString* customClass;
@property (nonatomic, retain) NSString* previewImage;
@property (nonatomic, assign) CGPoint previewAnchorpoint;
@property (nonatomic, retain) id properties;

- (id) initWithFile:(NSString*) f assetsPath:(NSString*)assetsPath;

@end

// CCBTemplateNode
@class CCBTemplate;

@interface CCBTemplateNode : CCSprite
{
    CCBTemplate* ccbTemplate;
    
}

@property (nonatomic,retain) CCBTemplate* ccbTemplate;

- (id)initWithTemplate:(CCBTemplate*)t;

@end