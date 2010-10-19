//
// Copyright 2010 Itty Bitty Apps Pty Ltd
// 
// Licensed under the Apache License, Version 2.0 (the "License"); you may not use this 
// file except in compliance with the License. You may obtain a copy of the License at 
// 
// http://www.apache.org/licenses/LICENSE-2.0 
// 
// Unless required by applicable law or agreed to in writing, software distributed under
// the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF 
// ANY KIND, either express or implied. See the License for the specific language governing
// permissions and limitations under the License.
//

#import "IBAInputRequestorFormField.h"
#import "IBATextFormFieldCell.h"
#import "IBAPickListOptionsProvider.h"


@interface IBAPickListFormField : IBAInputRequestorFormField <IBAPickListOptionsProvider> {
	IBATextFormFieldCell *pickListCell;
	IBAPickListSelectionMode selectionMode;
	NSArray *pickListOptions;
}

@property (nonatomic, retain) IBATextFormFieldCell *pickListCell;
@property (nonatomic, assign) IBAPickListSelectionMode selectionMode;
@property (nonatomic, copy) NSArray *pickListOptions;

- (id)initWithKey:(NSString *)aKey title:(NSString *)aTitle valueTransformer:(NSValueTransformer *)aValueTransformer 
	selectionMode:(IBAPickListSelectionMode)selectionMode options:(NSArray *)thePickListOptions;
- (id)initWithKey:(NSString *)aKey title:(NSString *)aTitle valueTransformer:(NSValueTransformer *)aValueTransformer 
	selectionMode:(IBAPickListSelectionMode)theSelectionMode options:(NSArray *)thePickListOptions 
		 editable:(BOOL)editableFlag movable:(BOOL)movableFlag;

@end


@interface IBAPickListFormOption : NSObject <IBAPickListOption> {
	NSString *name;
	UIImage *iconImage;
}

+ (NSArray *)pickListOptionsForStrings:(NSArray *)optionNames;
- (id)initWithName:(NSString *)name iconImage:(UIImage *)iconImage;

@end


@interface IBAPickListFormOptionsStringTransformer : NSValueTransformer {
	NSArray *pickListOptions;
}

- (id)initWithPickListOptions:(NSArray *)pickListOptions;
@property (nonatomic, copy) NSArray *pickListOptions;
@end