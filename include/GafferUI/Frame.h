//////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2011, John Haddon. All rights reserved.
//  Copyright (c) 2012, Image Engine Design Inc. All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are
//  met:
//
//      * Redistributions of source code must retain the above
//        copyright notice, this list of conditions and the following
//        disclaimer.
//
//      * Redistributions in binary form must reproduce the above
//        copyright notice, this list of conditions and the following
//        disclaimer in the documentation and/or other materials provided with
//        the distribution.
//
//      * Neither the name of John Haddon nor the names of
//        any other contributors to this software may be used to endorse or
//        promote products derived from this software without specific prior
//        written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
//  IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
//  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
//  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
//  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
//  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
//  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
//  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
//  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
//  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
//  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//////////////////////////////////////////////////////////////////////////

#ifndef GAFFERUI_FRAME_H
#define GAFFERUI_FRAME_H

#include "GafferUI/IndividualContainer.h"

namespace GafferUI
{

/// The Frame class draws a frame around its child.
class GAFFERUI_API Frame : public IndividualContainer
{

	public :

		Frame( GadgetPtr child );
		~Frame() override;

		GAFFER_GRAPHCOMPONENT_DECLARE_TYPE( GafferUI::Frame, FrameTypeId, IndividualContainer );

		Imath::Box3f bound() const override;

	protected :

		void doRenderLayer( Layer layer, const Style *style ) const override;

	private :

		float m_border;

};

IE_CORE_DECLAREPTR( Frame );

[[deprecated("Use `Frame::Iterator` instead")]]
typedef Gaffer::FilteredChildIterator<Gaffer::TypePredicate<Frame> > FrameIterator;
[[deprecated("Use `Frame::RecursiveIterator` instead")]]
typedef Gaffer::FilteredRecursiveChildIterator<Gaffer::TypePredicate<Frame> > RecursiveFrameIterator;

} // namespace GafferUI

#endif // GAFFERUI_FRAME_H
