/**
 * Copyright (c) 2014-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// @Generated by gentest/gentest.rb from gentest/fixtures/YGChildMeasureAndConstraints.html

// Test fixture:
// <div id="child_min_constraints_when_shrinking" style="height: 50px; width: 375px; flex-direction: row;">
//   <div style="flex-shrink:1; flex-basis: 400px; height: 50px;"></div>
//   <div style="flex-shrink:10000; flex-basis: 400px; padding: 1px; flex-direction: row;">
//     <div style="min-width: 50px; margin-right: 4px"></div>
//     <div style="min-width: 50px; margin: 8px;"></div>
//   </div>
// </div>

#include <gtest/gtest.h>
#include <yoga/Yoga.h>

TEST(YogaTest, child_min_constraints_when_shrinking) {
  const YGConfigRef config = YGConfigNew();

  const YGNodeRef root = YGNodeNewWithConfig(config);
  YGNodeStyleSetFlexDirection(root, YGFlexDirectionRow);
  YGNodeStyleSetWidth(root, 375);
  YGNodeStyleSetHeight(root, 50);

  const YGNodeRef root_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetFlexShrink(root_child0, 1);
  YGNodeStyleSetFlexBasis(root_child0, 400);
  YGNodeStyleSetHeight(root_child0, 50);
  YGNodeInsertChild(root, root_child0, 0);

  const YGNodeRef root_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetFlexDirection(root_child1, YGFlexDirectionRow);
  YGNodeStyleSetFlexShrink(root_child1, 10000);
  YGNodeStyleSetFlexBasis(root_child1, 400);
  YGNodeStyleSetPadding(root_child1, YGEdgeLeft, 1);
  YGNodeStyleSetPadding(root_child1, YGEdgeTop, 1);
  YGNodeStyleSetPadding(root_child1, YGEdgeRight, 1);
  YGNodeStyleSetPadding(root_child1, YGEdgeBottom, 1);
  YGNodeInsertChild(root, root_child1, 1);

  const YGNodeRef root_child1_child0 = YGNodeNewWithConfig(config);
  YGNodeStyleSetMargin(root_child1_child0, YGEdgeRight, 4);
  YGNodeStyleSetMinWidth(root_child1_child0, 50);
  YGNodeInsertChild(root_child1, root_child1_child0, 0);

  const YGNodeRef root_child1_child1 = YGNodeNewWithConfig(config);
  YGNodeStyleSetMargin(root_child1_child1, YGEdgeLeft, 8);
  YGNodeStyleSetMargin(root_child1_child1, YGEdgeTop, 8);
  YGNodeStyleSetMargin(root_child1_child1, YGEdgeRight, 8);
  YGNodeStyleSetMargin(root_child1_child1, YGEdgeBottom, 8);
  YGNodeStyleSetMinWidth(root_child1_child1, 50);
  YGNodeInsertChild(root_child1, root_child1_child1, 1);
  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionLTR);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(375, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(253, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(253, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(122, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(1, YGNodeLayoutGetLeft(root_child1_child0));
  ASSERT_FLOAT_EQ(1, YGNodeLayoutGetTop(root_child1_child0));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetWidth(root_child1_child0));
  ASSERT_FLOAT_EQ(48, YGNodeLayoutGetHeight(root_child1_child0));

  ASSERT_FLOAT_EQ(63, YGNodeLayoutGetLeft(root_child1_child1));
  ASSERT_FLOAT_EQ(9, YGNodeLayoutGetTop(root_child1_child1));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetWidth(root_child1_child1));
  ASSERT_FLOAT_EQ(32, YGNodeLayoutGetHeight(root_child1_child1));

  YGNodeCalculateLayout(root, YGUndefined, YGUndefined, YGDirectionRTL);

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root));
  ASSERT_FLOAT_EQ(375, YGNodeLayoutGetWidth(root));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root));

  ASSERT_FLOAT_EQ(122, YGNodeLayoutGetLeft(root_child0));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child0));
  ASSERT_FLOAT_EQ(253, YGNodeLayoutGetWidth(root_child0));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root_child0));

  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetLeft(root_child1));
  ASSERT_FLOAT_EQ(0, YGNodeLayoutGetTop(root_child1));
  ASSERT_FLOAT_EQ(122, YGNodeLayoutGetWidth(root_child1));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetHeight(root_child1));

  ASSERT_FLOAT_EQ(67, YGNodeLayoutGetLeft(root_child1_child0));
  ASSERT_FLOAT_EQ(1, YGNodeLayoutGetTop(root_child1_child0));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetWidth(root_child1_child0));
  ASSERT_FLOAT_EQ(48, YGNodeLayoutGetHeight(root_child1_child0));

  ASSERT_FLOAT_EQ(9, YGNodeLayoutGetLeft(root_child1_child1));
  ASSERT_FLOAT_EQ(9, YGNodeLayoutGetTop(root_child1_child1));
  ASSERT_FLOAT_EQ(50, YGNodeLayoutGetWidth(root_child1_child1));
  ASSERT_FLOAT_EQ(32, YGNodeLayoutGetHeight(root_child1_child1));

  YGNodeFreeRecursive(root);

  YGConfigFree(config);
}
