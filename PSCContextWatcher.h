//
//  PSCContextWatcher.h
//  Companion
//
//  Created by Philip Messlehner on 28.02.13.
//  Copyright (c) 2013 Philip Messlehner. All rights reserved.
//
//  Copyright 2010 Zarra Studios, LLC All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation
//  files (the "Software"), to deal in the Software without
//  restriction, including without limitation the rights to use,
//  copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following
//  conditions:
//
//  The above copyright notice and this permission notice shall be
//  included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
//  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
//  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
//  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.

#import <Foundation/Foundation.h>

@protocol PSCContextWatcherDelegate <NSObject>

@required
- (void)context:(NSManagedObjectContext *)context didSaveWithResults:(NSDictionary *)results;

@end

@interface PSCContextWatcher : NSObject

+ (instancetype)watcherWithContext:(NSManagedObjectContext *)context;
- (id)initWithManagedObjectContext:(NSManagedObjectContext *)context;
- (void)addEntityClassToWatch:(Class)class withPredicate:(NSPredicate *)predicate;
- (void)addEntityToWatch:(NSString *)name withPredicate:(NSPredicate *)predicate;

@property (nonatomic, assign) id<PSCContextWatcherDelegate> delegate;

@end
