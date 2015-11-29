/*
Copyright (C) 2014 Bastien Oudot

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
#ifndef SB_DATASET_H
#define SB_DATASET_H

#include <sb-core/sb-abstractobject.h>

#include <sb-core/sb-abstractdata.h>

namespace sb
{

class SB_CORE_API DataSet : public AbstractObject
{

    SB_DECLARE_OBJECT(DataSet, "sb::DataSet")

public:

    class Private;

    virtual
    ~DataSet
    (
    );

    IndexRange
    get_index_range
    (
    )
    const;

    IndexCollection
    get_defined_indices
    (
    )
    const;

    IndexCollection
    get_wanted_indices
    (
    )
    const;

    SharedData
    get_data
    (
        double index_
    )
    const;

    void
    set_data
    (
        double index_,
        const SharedData& value_
    );

private:

    static
    void
    construct
    (
        DataSet* this_
    );

    Private*
    d_ptr;

};

using SharedDataSet = Shared<DataSet>;

static
SharedDataSet
(&create_shared_data_set)
(
    const std::string& name_
) = create_shared<DataSet>;

}

#endif // SB_DATASET_H