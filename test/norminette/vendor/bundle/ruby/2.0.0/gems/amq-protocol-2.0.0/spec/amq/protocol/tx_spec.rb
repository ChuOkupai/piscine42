# encoding: binary

require File.expand_path('../../../spec_helper', __FILE__)


module AMQ
  module Protocol
    class Tx
      describe Select do
        describe '.encode' do
          it 'encodes the parameters into a MethodFrame' do
            channel = 1
            method_frame = Select.encode(channel)
            expect(method_frame.payload).to eq("\000Z\000\n")
            expect(method_frame.channel).to eq(1)
          end
        end
      end

      # describe SelectOk do
      #   describe '.decode' do
      #   end
      # end

      describe Commit do
        describe '.encode' do
          it 'encodes the parameters into a MethodFrame' do
            channel = 1
            method_frame = Commit.encode(channel)
            expect(method_frame.payload).to eq("\000Z\000\024")
            expect(method_frame.channel).to eq(1)
          end
        end
      end
      
      # describe CommitOk do
      #   describe '.decode' do
      #   end
      # end

      describe Rollback do
        describe '.encode' do
          it 'encodes the parameters into a MethodFrame' do
            channel = 1
            method_frame = Rollback.encode(channel)
            expect(method_frame.payload).to eq("\000Z\000\036")
            expect(method_frame.channel).to eq(1)
          end
        end
      end

      # describe RollbackOk do
      #   describe '.decode' do
      #   end
      # end
    end
  end
end
