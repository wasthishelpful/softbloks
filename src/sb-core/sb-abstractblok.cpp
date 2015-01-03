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
#include "sb-abstractblok.h"

#include "sb-abstractblok-private.h"

using namespace sb;

AbstractBlok::Private::Private
(
    AbstractBlok* _q
):
    q_ptr               (_q),
    minimum_input_count (0),
    maximum_input_count (-1),
    input_count         (0),
    minimum_output_count(0),
    maximum_output_count(-1),
    output_count        (0)
{
}

void
AbstractBlok::Private::set_input_count
(
    int _value
)
{
    this->input_count =
        this->minimum_input_count =
        this->maximum_input_count =
        _value;
}

void
AbstractBlok::Private::set_input_count
(
    int _minimum,
    int _maximum
)
{
    this->minimum_input_count = _minimum;
    this->maximum_input_count = _maximum;

    this->input_count = this->minimum_input_count;
}

void
AbstractBlok::Private::set_output_count
(
    int _value
)
{
    this->output_count =
        this->minimum_output_count =
        this->maximum_output_count =
        _value;
}

void
AbstractBlok::Private::set_output_count
(
    int _minimum,
    int _maximum
)
{
    this->minimum_output_count = _minimum;
    this->maximum_output_count = _maximum;

    this->output_count = this->minimum_output_count;
}

AbstractBlok::Private*
AbstractBlok::Private::from
(
    AbstractBlok* _q
)
{
    return _q->d_ptr;
}

AbstractBlok::AbstractBlok
(
)
{
    d_ptr = new Private(this);
}

AbstractBlok::~AbstractBlok
(
)
{
    delete d_ptr;
}

int
AbstractBlok::get_minimum_input_count
(
)
const
{
    return d_ptr->minimum_input_count;
}

int
AbstractBlok::get_maximum_input_count
(
)
const
{
    return d_ptr->maximum_input_count;
}

int
AbstractBlok::get_input_count
(
)
const
{
    return d_ptr->input_count;
}

int
AbstractBlok::get_minimum_output_count
(
)
const
{
    return d_ptr->minimum_output_count;
}

int
AbstractBlok::get_maximum_output_count
(
)
const
{
    return d_ptr->maximum_output_count;
}

int
AbstractBlok::get_output_count
(
)
const
{
    return d_ptr->output_count;
}
