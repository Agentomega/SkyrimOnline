#pragma once

#include <Overlay/ShardList.h>
#include <Logic/GameState.hpp>

namespace Skyrim
{
	namespace Logic
	{
		namespace State
		{
			class ShardList : public GameState
			{
			public:
				ShardList();
				virtual ~ShardList();

				void OnEnter();
				void OnLeave();
				void OnUpdate(uint32_t pDelta);
				void OnConnect(bool pConnected);

				void OnShardPick(const std::string& pShard);
				DEPRECATED(void OnHost());

				bool IsSwitchingAllowed();

				uint32_t GetId()
				{
					return 'shar';
				}

			private:

				boost::shared_ptr<Overlay::ShardList> mShardList;
			};
		}
	}
}