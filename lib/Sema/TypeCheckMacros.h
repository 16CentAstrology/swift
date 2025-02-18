//===--- TypeCheckConcurrency.h - Concurrency -------------------*- C++ -*-===//
//
// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2020 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See https://swift.org/LICENSE.txt for license information
// See https://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//
//===----------------------------------------------------------------------===//
//
// This file provides type checking support for macros.
//
//===----------------------------------------------------------------------===//
#ifndef SWIFT_SEMA_TYPECHECKMACROS_H
#define SWIFT_SEMA_TYPECHECKMACROS_H

#include "swift/AST/ConcreteDeclRef.h"
#include "swift/AST/Type.h"

namespace swift {

class CustomAttr;
class Expr;
class MacroDecl;
class MacroExpansionDecl;
class TypeRepr;

/// Expands the given macro expression and type-check the result with
/// the given expanded type.
///
/// \returns the type-checked replacement expression, or NULL if the
// macro could not be expanded.
Expr *expandMacroExpr(
    DeclContext *dc, Expr *expr, ConcreteDeclRef macroRef, Type expandedType);

/// Expands the given macro expansion declaration, type-checks the replacement
/// declarations, and adds them to \p results.
///
/// \returns true if expansion succeeded, false if failed.
bool expandFreestandingDeclarationMacro(
    MacroExpansionDecl *med, SmallVectorImpl<Decl *> &results);

/// Expand the accessors for the given storage declaration based on the
/// custom attribute that references the given macro.
void expandAccessors(
    AbstractStorageDecl *storage, CustomAttr *attr, MacroDecl *macro
);

} // end namespace swift

#endif /* SWIFT_SEMA_TYPECHECKMACROS_H */

