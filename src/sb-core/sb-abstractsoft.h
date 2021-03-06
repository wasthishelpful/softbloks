/*
Copyright (C) 2014-2015 Bastien Oudot and Romain Guillemot

This file is part of Softbloks.
Softbloks is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Softbloks is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with Softbloks.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef SB_ABSTRACTSOFT_H
#define SB_ABSTRACTSOFT_H

#include <sb-core/sb-abstractobject.h>

namespace sb
{

/// \brief The AbstractSoft class represents a particular program in a Softbloks environment.
///
/// Such programs are designed to run in a Softbloks application (e.g. Softrun or Software).
class SB_CORE_API AbstractSoft : public AbstractObject
{

    SB_SELF(sb::AbstractSoft)

    SB_NAME("sb.AbstractSoft")

public:

    class Private;

    /// Constructs a soft.
    AbstractSoft
    (
    );

    /// Destroys this object.
    virtual
    ~AbstractSoft
    (
    );

private:

    /// \cond INTERNAL
    Private*
    d_ptr;
    /// \endcond

};

/// Constant value representing the format of a valid soft (inheriting
/// AbstractSoft).
const ObjectFormat
ANY_SOFT_FORMAT = {
    AbstractSoft::get_type_names(),
    AbstractSoft::get_properties()
};

/// Alias for a managed soft with shared ownership.
using SharedSoft = Shared<AbstractSoft>;

/// Alias for create_shared<AbstractSoft>().
static
SharedSoft
(&create_shared_soft)
(
    const std::string& name_
) = create_shared<AbstractSoft>;

}

#endif // SB_ABSTRACTSOFT_H
